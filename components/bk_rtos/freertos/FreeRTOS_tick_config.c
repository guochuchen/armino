/*
 * FreeRTOS Kernel V10.3.1
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Platform includes. */
#include "platform.h"
#include "sys_driver.h"

#if CONFIG_SYSTEM_CTRL
#include <modules/pm.h>
#endif

#if CONFIG_AON_RTC
#include <driver/aon_rtc.h>
#include <driver/aon_rtc_types.h>
#endif

#include <components/log.h>

#define TAG  "os"

extern uint64_t ullNextTime;
extern const size_t uxTimerIncrementsForOneTick;
extern uint32_t pm_debug_mode();
extern void bk_task_wdt_feed(void);

#if( configUSE_TICKLESS_IDLE != 0 )
	/* Flag set from the timer interrupt to allow the sleep processing to know if
	sleep mode was exited because of a tick interrupt, or an interrupt
	generated by something else. */
extern volatile BaseType_t xTickFlag;
#endif /* configUSE_TICKLESS_IDLE */


extern void riscv_set_mtimercmp(u64 new_time);
extern u64 riscv_get_mtimer(void);
extern u64 riscv_get_mtimercmp(void);
extern unsigned int arch_int_disable(void);
extern void arch_int_restore(int int_flag);

#define prvReadMtime()	 riscv_get_mtimer()
#define prvWriteMtimecmp(new_timecmp)	riscv_set_mtimercmp(new_timecmp)

#if CONFIG_AON_RTC
	#define RTC_WAKEUP_TIMER       "rtc_wk"
	#define OS_MS_PER_TICK          (1000/configTICK_RATE_HZ)
	#define RTC_TICKS_PER_OS_TICK   (RTC_TICKS_PER_1MS*OS_MS_PER_TICK)
	#define OS_SLEEP_MIN_TICKS      (3)
	#define OS_SLEEP_MAX_TICKS      (60*60*1000/OS_MS_PER_TICK)   //60min

	static uint64_t base_aon_time = 0;
	static uint32_t base_os_time = 0;
#endif


__maybe_unused void rtos_init_base_time(void) {
#if CONFIG_AON_RTC
	base_aon_time = bk_aon_rtc_get_current_tick(AON_RTC_ID_1);
	base_os_time = rtos_get_time();
	BK_LOGI(TAG, "os time(%dms),rtc time(%dms).\r\n", base_os_time,
		(uint32_t)base_aon_time/RTC_TICKS_PER_1MS);
	BK_LOGI(TAG, "base aon rtc time: %d:%d\r\n", (uint32_t)(base_aon_time >> 32),
		(uint32_t)(base_aon_time & 0xFFFFFFFF));
#endif
}

uint32_t rtos_get_time_diff(void) {
#if CONFIG_AON_RTC
	uint64_t cur_aon_time = bk_aon_rtc_get_current_tick(AON_RTC_ID_1);
	uint64_t cur_os_time = (uint64_t)rtos_get_time(); //ms
	uint64_t diff_time = (cur_aon_time - base_aon_time)/RTC_TICKS_PER_1MS; //ms
	uint32_t diff_ms = 0;

	if((uint32_t)(diff_time >> 32) & 0x7FF0000) {
		BK_LOGI(TAG, "aon_rtc overfollow....\r\n");
		BK_DUMP_OUT("diff time: 0x%x:0x%08x\r\n", (u32)(diff_time >> 32), (u32)(diff_time & 0xFFFFFFFF));
		return 0;
	}

	if (diff_time + base_os_time < cur_os_time) {
		return 0;
	}

	diff_ms = (uint32_t)(diff_time + base_os_time - cur_os_time);

	if (diff_ms > 20000) {
		BK_LOGI(TAG, "aon_rtc diff_ms: %dms.\r\n", diff_ms);
		BK_LOGI(TAG, "cur aon time: 0x%x:0x%08x\r\n", (u32)(cur_aon_time >> 32), (u32)(cur_aon_time & 0xFFFFFFFF));
	}

	return  diff_ms / OS_MS_PER_TICK; // tick
#else
	return 0;
#endif
}

/*-----------------------------------------------------------*/

#if( configUSE_TICKLESS_IDLE != 0 )

/* Stop mtime interrupt by setting timer compare register to maximum value.
The return value is previous value of timer compare register.
Again, like prvWriteMtimecmp(), We assume mtime overflow doesn't occur. */
static portFORCE_INLINE uint64_t prvStopMtimeIrq( void )
{
	uint64_t ullSavedMtimecmp;
	UBaseType_t uxSavedStatus;

	uxSavedStatus = arch_int_disable();

	ullSavedMtimecmp = riscv_get_mtimercmp();
	riscv_set_mtimercmp(UINT64_MAX);

	arch_int_restore( uxSavedStatus );

	return ullSavedMtimecmp;
}

#endif /* configUSE_TICKLESS_IDLE */

#if (configUSE_TICKLESS_IDLE == 1)
__attribute__((section(".itcm_sec_code")))	void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime )
{
	/* The maximum number of tick periods that can be suppressed is limited by
	the resolution of the Timer */
	#define portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS ( (1ULL << 60) / uxTimerIncrementsForOneTick )

	/* Unit: cycle */
	uint64_t ullNextTickTime, ullWakeUpTime, ullCurrentTime;

	/* Unit: tick */
	TickType_t xCompleteTickPeriods, xTickPeriodsBeforeWakeup, xModifiableIdleTime;

	/* To avoid integer overflow when assigning maximum tick periods
	to xExpectedIdleTime, check portMAX_DELAY first.
	p.s. xExpectedIdleTime is always lower than portMAX_DELAY */
	if( portMAX_DELAY > portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS )
	{
		/* if portMAX_DELAY > portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS, then the
		size of TickType_t is larger than or equal to maximum tick periods */
		if( xExpectedIdleTime > portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS )
		{
			xExpectedIdleTime = (TickType_t) portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS;
		}
	}

	/* Stop mtime interrupt */
	ullNextTickTime = prvStopMtimeIrq();

	/* Calculate the mtimecmp value to wait xExpectedIdleTime tick periods.
	Wakeup time is at ( xExpectedIdleTime - 1 ) ticks after next tick. */
	ullWakeUpTime = ullNextTickTime + ( ( xExpectedIdleTime - 1 ) * (uint64_t)uxTimerIncrementsForOneTick );

	portDISABLE_INTERRUPTS();
	if( eTaskConfirmSleepModeStatus() == eAbortSleep )
	{

		/* Set reload value and restart timer */
		prvWriteMtimecmp( ullNextTickTime );

		/* Re-enable interrupts. */
		portENABLE_INTERRUPTS();
	}
	else
	{
		/* The tick flag is set to false before sleeping. If it is true when
		sleep mode is exited then sleep mode was probably exited because the
		tick was suppressed for the entire xExpectedIdleTime period. */
		xTickFlag = 0;

		/* Set wakeup time and restart timer. Also prepare next mtimecmp value
		for Timer ISR. */
		prvWriteMtimecmp( ullWakeUpTime );
		ullNextTime = ullWakeUpTime + uxTimerIncrementsForOneTick;

		/* Sleep until something happens.  configPRE_SLEEP_PROCESSING() can
		set its parameter to 0 to indicate that its implementation contains
		its own wait for interrupt or wait for event instruction, and so wfi
		should not be executed again.  However, the original expected idle
		time variable must remain unmodified, so a copy is taken. */
		xModifiableIdleTime = xExpectedIdleTime;
		configPRE_SLEEP_PROCESSING( xModifiableIdleTime );
		if( xModifiableIdleTime > 0 )
		{
			__asm volatile( "wfi" );
		}
		configPOST_SLEEP_PROCESSING( xExpectedIdleTime );

		/* Re-enable interrupts to allow the interrupt that brought the MCU
		out of sleep mode to execute immediately. */
		portENABLE_INTERRUPTS();

		/* Disable interrupts again to avoid timer ISR runs after checking
		xTickFlag. */
		portDISABLE_INTERRUPTS();

		if( xTickFlag == 1 )
		{
			/* As the pending tick will be processed as soon as this
			function exits, the tick value maintained by the tick is stepped
			forward by one less than the time spent waiting. */
			xCompleteTickPeriods = xExpectedIdleTime - 1;

			/* Note: mtimecmp is correct in this condition, so we doesn't
			need to access it */
		}
		else
		{
			ullCurrentTime = prvReadMtime();

			if( ullCurrentTime >= ullWakeUpTime )
			{
				/* Tick interrupt is pending because it occurs after
				disabling MIE. The tick value is stepped forward by
				the time spent waiting. */
				xCompleteTickPeriods = xExpectedIdleTime - 1;
			}
			else
			{
				/* Something other than the tick interrupt ended the sleep.
				Work out how long the sleep lasted rounded to complete tick
				periods. */

				/* Round up the tick period before wakeup to the Tick unit */
				xTickPeriodsBeforeWakeup = ( ullWakeUpTime - ullCurrentTime - 1 ) / uxTimerIncrementsForOneTick + 1;
				xCompleteTickPeriods = xExpectedIdleTime - xTickPeriodsBeforeWakeup;
			}

			ullNextTime = ullNextTickTime + ( ( ( uint64_t ) xCompleteTickPeriods ) * uxTimerIncrementsForOneTick );
			prvWriteMtimecmp( ullNextTime );

			/* Prepare next mtimecmp value for Timer ISR. */
		    ullNextTime += ( uint64_t ) uxTimerIncrementsForOneTick;
		}

		vTaskStepTick( xCompleteTickPeriods );

		/* Exit with interrpts enabled. */
		portENABLE_INTERRUPTS();
	}
}
#endif //if (configUSE_TICKLESS_IDLE == 1)
/*-----------------------------------------------------------*/

#if (configUSE_TICKLESS_IDLE == 2)


__attribute__((section(".itcm_sec_code")))	void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime )
{
	/* The maximum number of tick periods that can be suppressed is limited by
	the resolution of the Timer */
#if CONFIG_AON_RTC
	#define portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS ( (1ULL << 32) / RTC_TICKS_PER_OS_TICK )
	#define portULL_MINIMUM_POSSIBLE_SUPPRESSED_TICKS ( 2 )

#endif
	UBaseType_t uxSavedInterruptState;

	TickType_t  xSleepTicks;

#if CONFIG_SYSTEM_CTRL
	TickType_t xModifiableIdleTime;
#endif

	/* To avoid integer overflow when assigning maximum tick periods
	to xExpectedIdleTime, check portMAX_DELAY first.
	p.s. xExpectedIdleTime is always lower than portMAX_DELAY */
	{
		/* if portMAX_DELAY > portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS, then the
		size of TickType_t is larger than or equal to maximum tick periods */
		if( xExpectedIdleTime > portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS )
		{
			xExpectedIdleTime = (TickType_t) portULL_MAXIMUM_POSSIBLE_SUPPRESSED_TICKS;
		}
	}


	uxSavedInterruptState = portSET_INTERRUPT_MASK_FROM_ISR();

	if( eTaskConfirmSleepModeStatus() == eAbortSleep )
	{
		/* Re-enable interrupts. */
		portCLEAR_INTERRUPT_MASK_FROM_ISR(uxSavedInterruptState);
	}
	else
	{
		/* The tick flag is set to false before sleeping. If it is true when
		sleep mode is exited then sleep mode was probably exited because the
		tick was suppressed for the entire xExpectedIdleTime period. */
		// xTickFlag = 0;

		/* Set wakeup timer. */
		// vSetWakeUpTimer(xWakeUpTimes);

#if CONFIG_SYSTEM_CTRL
		/* Sleep until something happens.  configPRE_SLEEP_PROCESSING() can
		set its parameter to 0 to indicate that its implementation contains
		its own wait for interrupt or wait for event instruction, and so wfi
		should not be executed again.  However, the original expected idle
		time variable must remain unmodified, so a copy is taken. */
		xModifiableIdleTime = xExpectedIdleTime;
		bk_pm_suppress_ticks_and_sleep(xModifiableIdleTime);
#else
		__asm volatile( "wfi" );
#endif

#if CONFIG_AON_RTC
		xSleepTicks = rtos_get_time_diff();

		if(xSleepTicks != 0 && xSleepTicks != 1) {
			if(pm_debug_mode()&0x8) {
            	BK_LOGI(TAG, "expect%dsleep%dms.\r\n", xExpectedIdleTime<<1, xSleepTicks<<1);
   			}

			vTaskStepTick(xSleepTicks - 1);
		}
#endif
		/* Exit with interrpts enabled. */
		portCLEAR_INTERRUPT_MASK_FROM_ISR(uxSavedInterruptState);
	}
}

#endif // (configUSE_TICKLESS_IDLE == 2)

