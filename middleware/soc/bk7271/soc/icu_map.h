// Copyright 2020-2021 Beken
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <driver/int_types.h>
#include <soc/soc.h>

#define GROUP0     0
#define GROUP1     1
#define INVALID    0

#define ICU_DEV_MAP  \
{\
	{INT_SRC_UART1, 0, ICU_PRI_IRQ_UART1 , GROUP0}, \
	{INT_SRC_UART2, 1, ICU_PRI_IRQ_UART2 , GROUP0}, \
	{INT_SRC_I2C0, 3, ICU_PRI_IRQ_I2C0, GROUP0}, \
	{INT_SRC_IRDA, 12, ICU_PRI_IRQ_IRDA , GROUP0}, \
	{INT_SRC_I2S, INVALID, INVALID , INVALID}, \
	{INT_SRC_I2C1, 4, ICU_PRI_IRQ_I2C1 , GROUP0}, \
	{INT_SRC_SPI, 8, ICU_PRI_IRQ_SPI , GROUP0}, \
	{INT_SRC_GPIO, 11, ICU_PRI_IRQ_GPIO , GROUP0}, \
	{INT_SRC_TIMER, 13, ICU_PRI_IRQ_TIMER , GROUP0}, \
	{INT_SRC_PWM, 14, ICU_PRI_IRQ_PWM , GROUP0}, \
	{INT_SRC_AUDIO, INVALID, INVALID , INVALID}, \
	{INT_SRC_SARADC, 16, ICU_PRI_IRQ_UART1 , GROUP0}, \
	{INT_SRC_SDIO, 6, ICU_PRI_IRQ_SDIO_HOST , GROUP0}, \
	{INT_SRC_USB, 7, ICU_PRI_IRQ_USB1 , GROUP0}, \
	{INT_SRC_FFT, INVALID, INVALID , INVALID}, \
	{INT_SRC_GDMA, 20, ICU_PRI_IRQ_GENERDMA , GROUP0}, \
	{INT_SRC_MODEM, 24, ICU_PRI_IRQ_MODEM , GROUP0}, \
	{INT_SRC_MAC_TXRX_TIMER, 25, ICU_PRI_IRQ_MAC_TX_RX_TIMER , GROUP0}, \
	{INT_SRC_MAC_TXRX_MISC, 26, ICU_PRI_IRQ_MAC_TX_RX_MISC , GROUP0}, \
	{INT_SRC_MAC_RX_TRIGGER, 27, ICU_PRI_IRQ_MAC_RX_TRIGGER , GROUP0}, \
	{INT_SRC_MAC_TX_TRIGGER, 28, ICU_PRI_IRQ_MAC_TX_TRIGGER , GROUP0}, \
	{INT_SRC_MAC_PROT_TRIGGER, 29, ICU_PRI_IRQ_MAC_PROT_TRIGGER , GROUP0}, \
	{INT_SRC_MAC_GENERAL, 30, ICU_PRI_IRQ_MAC_GENERAL , GROUP0}, \
	{INT_SRC_SDIO_DMA, 19, ICU_PRI_IRQ_SDIO_DMA , GROUP0}, \
	{INT_SRC_USB_PLUG_INOUT, 1, ICU_PRI_FIQ_USB_PLUG_INOUT , GROUP1}, \
	{INT_SRC_SECURITY, 23, ICU_PRI_IRQ_SECURITY , GROUP0}, \
	{INT_SRC_MAC_WAKEUP, 31, ICU_PRI_IRQ_MAC_WAKEUP , GROUP0}, \
	{INT_SRC_HSSPI_SLAVE, INVALID, INVALID , INVALID}, \
	{INT_SRC_PLL_UNLOCK, 0, ICU_PRI_FIQ_PLL_UNLOCK , GROUP1}, \
	{INT_SRC_JPEG, 7, ICU_PRI_FIQ_JPEG , GROUP1}, \
	{INT_SRC_BLE, INVALID, INVALID , INVALID}, \
	{INT_SRC_PSRAM, 17, ICU_PRI_IRQ_QSPI , GROUP0}, \
	{INT_SRC_LA, INVALID, INVALID , INVALID}, \
	{INT_SRC_BTDM, INVALID, INVALID , INVALID}, \
	{INT_SRC_BT, INVALID, INVALID , INVALID}, \
	{INT_SRC_UART3, 2, ICU_PRI_IRQ_UART3 , GROUP0}, \
	{INT_SRC_I2C2, 5, ICU_PRI_IRQ_I2C2 , GROUP0}, \
	{INT_SRC_SPI2, 9, ICU_PRI_IRQ_SPI2 , GROUP0}, \
	{INT_SRC_SPI3, 10, ICU_PRI_IRQ_SPI3 , GROUP0}, \
	{INT_SRC_PWM2, 15, ICU_PRI_IRQ_PWM , GROUP0}, \
	{INT_SRC_USB2, 18, ICU_PRI_IRQ_USB2 , GROUP0}, \
	{INT_SRC_MAILBOX0, 21, ICU_PRI_IRQ_MAILBOX0 , GROUP0}, \
	{INT_SRC_MAILBOX1, 22, ICU_PRI_IRQ_MAILBOX1 , GROUP0}, \
	{INT_SRC_BT_WDT, 2, ICU_PRI_FIQ_BT_WDT , GROUP1}, \
	{INT_SRC_DSP_WDT, 3, ICU_PRI_FIQ_DSP_WDT , GROUP1}, \
	{INT_SRC_RTC, 4, ICU_PRI_FIQ_RTC , GROUP1}, \
	{INT_SRC_TOUCH, 5, ICU_PRI_FIQ_TOUCH , GROUP1}, \
	{INT_SRC_CEC, 6, ICU_PRI_FIQ_CEC , GROUP1}, \
}

#ifdef __cplusplus
}
#endif

