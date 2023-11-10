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
#include <stdio.h>
#include <driver/hal/hal_gpio_types.h>
#include <soc/soc.h>

#define BIT_64(i)	((1L) << (i))
#define GPIO_DEV_MAP  \
{\
	{GPIO_0, {GPIO_DEV_UART2_TXD, GPIO_DEV_I2C1_SCL, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_1, {GPIO_DEV_UART2_RXD, GPIO_DEV_I2C1_SDA, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_2, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_3, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_4, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_5, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_6, {GPIO_DEV_CLK13M, GPIO_DEV_PWM0, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_7, {GPIO_DEV_WIFI_ACTIVE, GPIO_DEV_PWM1, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_8, {GPIO_DEV_BT_ACTIVE, GPIO_DEV_PWM2, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_9, {GPIO_DEV_BT_PRIORITY, GPIO_DEV_PWM3, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_10,{GPIO_DEV_UART1_RXD, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_11, {GPIO_DEV_UART1_TXD, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_12, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_13, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_14, {GPIO_DEV_SDIO_HOST_CLK, GPIO_DEV_SPI0_SCK, GPIO_DEV_QSPI_FLASH_CLK, GPIO_DEV_INVALID}},\
	{GPIO_15, {GPIO_DEV_SDIO_HOST_DATA3, GPIO_DEV_SPI0_CSN, GPIO_DEV_QSPI_FLASH_CSN, GPIO_DEV_INVALID}},\
	{GPIO_16, {GPIO_DEV_SDIO_HOST_CMD, GPIO_DEV_SPI0_MOSI, GPIO_DEV_QSPI_IO0, GPIO_DEV_INVALID}},\
	{GPIO_17, {GPIO_DEV_SDIO_HOST_DATA0, GPIO_DEV_SPI0_MISO, GPIO_DEV_QSPI_IO1, GPIO_DEV_INVALID}},\
	{GPIO_18, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_19, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_20, {GPIO_DEV_I2C0_SCL, GPIO_DEV_JTAG_TCK, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_21, {GPIO_DEV_I2C0_SDA, GPIO_DEV_JTAG_TMS,  GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_22, {GPIO_DEV_CLK26M, GPIO_DEV_JTAG_TDI, GPIO_DEV_TXEN, GPIO_DEV_INVALID}},\
	{GPIO_23, {GPIO_DEV_ADC3, GPIO_DEV_JTAG_TDO, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_24, {GPIO_DEV_LPO_CLK, GPIO_DEV_PWM4, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_25, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_26, {GPIO_DEV_IRDA, GPIO_DEV_PWM5, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_27, {GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
	{GPIO_28, {GPIO_DEV_RXEN,  GPIO_DEV_INVALID, GPIO_DEV_INVALID, GPIO_DEV_INVALID}},\
}

/*
* Camera DVP GPIO MAP
*/
#define CAMERA_DVP_MCLK_PIN 		(GPIO_27)
#define CAMERA_DVP_PCLK_PIN 		(GPIO_29)
#define CAMERA_DVP_HSYNC_PIN 		(GPIO_30)
#define CAMERA_DVP_VSYNC_PIN 		(GPIO_31)
#define CAMERA_DVP_PXDATA0_PIN 		(GPIO_32)
#define CAMERA_DVP_PXDATA1_PIN 		(GPIO_33)
#define CAMERA_DVP_PXDATA2_PIN 		(GPIO_34)
#define CAMERA_DVP_PXDATA3_PIN 		(GPIO_35)
#define CAMERA_DVP_PXDATA4_PIN 		(GPIO_36)
#define CAMERA_DVP_PXDATA5_PIN 		(GPIO_37)
#define CAMERA_DVP_PXDATA6_PIN 		(GPIO_38)
#define CAMERA_DVP_PXDATA7_PIN 		(GPIO_39)

#define CAMERA_DVP_MCLK_FUNC 		(GPIO_DEV_JPEG_MCLK)
#define CAMERA_DVP_PCLK_FUNC 		(GPIO_DEV_JPEG_PCLK)
#define CAMERA_DVP_HSYNC_FUNC 		(GPIO_DEV_JPEG_HSYNC)
#define CAMERA_DVP_VSYNC_FUNC 		(GPIO_DEV_JPEG_VSYNC)
#define CAMERA_DVP_PXDATA0_FUNC 	(GPIO_DEV_JPEG_PXDATA0)
#define CAMERA_DVP_PXDATA1_FUNC 	(GPIO_DEV_JPEG_PXDATA1)
#define CAMERA_DVP_PXDATA2_FUNC 	(GPIO_DEV_JPEG_PXDATA2)
#define CAMERA_DVP_PXDATA3_FUNC 	(GPIO_DEV_JPEG_PXDATA3)
#define CAMERA_DVP_PXDATA4_FUNC 	(GPIO_DEV_JPEG_PXDATA4)
#define CAMERA_DVP_PXDATA5_FUNC 	(GPIO_DEV_JPEG_PXDATA5)
#define CAMERA_DVP_PXDATA6_FUNC 	(GPIO_DEV_JPEG_PXDATA6)
#define CAMERA_DVP_PXDATA7_FUNC 	(GPIO_DEV_JPEG_PXDATA7)

#define CAMERA_DVP_I2C_ID 			(CONFIG_CAMERA_I2C_ID)
#define CAMERA_DVP_I2C_BAUD_RATE	(I2C_BAUD_RATE_100KHZ)
#define CAMERA_DVP_I2C_MODE			(I2C_ADDR_MODE_7BIT)


/*
* LCD RGB GPIO MAP
*/
#define LCD_RGB_R0_PIN 				(GPIO_23)
#define LCD_RGB_R1_PIN 				(GPIO_22)
#define LCD_RGB_R2_PIN 				(GPIO_21)
#define LCD_RGB_R3_PIN 				(GPIO_20)
#define LCD_RGB_R4_PIN 				(GPIO_19)
#define LCD_RGB_G0_PIN 				(GPIO_42)
#define LCD_RGB_G1_PIN 				(GPIO_41)
#define LCD_RGB_G2_PIN 				(GPIO_40)
#define LCD_RGB_G3_PIN 				(GPIO_26)
#define LCD_RGB_G4_PIN 				(GPIO_25)
#define LCD_RGB_G5_PIN 				(GPIO_24)
#define LCD_RGB_B0_PIN 				(GPIO_47)
#define LCD_RGB_B1_PIN 				(GPIO_46)
#define LCD_RGB_B2_PIN 				(GPIO_45)
#define LCD_RGB_B3_PIN 				(GPIO_44)
#define LCD_RGB_B4_PIN 				(GPIO_43)
#define LCD_RGB_CLK_PIN 			(GPIO_14)
#define LCD_RGB_DISP_PIN 			(GPIO_15)
#define LCD_RGB_HSYNC_PIN 			(GPIO_17)
#define LCD_RGB_VSYNC_PIN 			(GPIO_18)
#define LCD_RGB_DE_PIN 				(GPIO_16)

#define LCD_RGB_R0_FUNC 			(GPIO_DEV_LCD_RGB11)
#define LCD_RGB_R1_FUNC 			(GPIO_DEV_LCD_RGB12)
#define LCD_RGB_R2_FUNC 			(GPIO_DEV_LCD_RGB13)
#define LCD_RGB_R3_FUNC 			(GPIO_DEV_LCD_RGB14)
#define LCD_RGB_R4_FUNC 			(GPIO_DEV_LCD_RGB15)
#define LCD_RGB_G0_FUNC 			(GPIO_DEV_LCD_RGB5)
#define LCD_RGB_G1_FUNC 			(GPIO_DEV_LCD_RGB6)
#define LCD_RGB_G2_FUNC 			(GPIO_DEV_LCD_RGB7)
#define LCD_RGB_G3_FUNC 			(GPIO_DEV_LCD_RGB8)
#define LCD_RGB_G4_FUNC 			(GPIO_DEV_LCD_RGB9)
#define LCD_RGB_G5_FUNC 			(GPIO_DEV_LCD_RGB10)
#define LCD_RGB_B0_FUNC 			(GPIO_DEV_LCD_RGB0)
#define LCD_RGB_B1_FUNC 			(GPIO_DEV_LCD_RGB1)
#define LCD_RGB_B2_FUNC 			(GPIO_DEV_LCD_RGB2)
#define LCD_RGB_B3_FUNC 			(GPIO_DEV_LCD_RGB3)
#define LCD_RGB_B4_FUNC 			(GPIO_DEV_LCD_RGB4)
#define LCD_RGB_CLK_FUNC 			(GPIO_DEV_LCD_RGB20)
#define LCD_RGB_DISP_FUNC 			(GPIO_DEV_LCD_RGB19)
#define LCD_RGB_HSYNC_FUNC 			(GPIO_DEV_LCD_RGB17)
#define LCD_RGB_VSYNC_FUNC 			(GPIO_DEV_LCD_RGB16)
#define LCD_RGB_DE_FUNC 			(GPIO_DEV_LCD_RGB18)

#define LCD_PWM_BACKLIGHT			(PWM_ID_1)

/*
* LCD MCU GPIO MAP
*/
#define LCD_MCU_D0_PIN 				(GPIO_47)
#define LCD_MCU_D1_PIN 				(GPIO_46)
#define LCD_MCU_D2_PIN 				(GPIO_45)
#define LCD_MCU_D3_PIN 				(GPIO_44)
#define LCD_MCU_D4_PIN 				(GPIO_43)
#define LCD_MCU_D5_PIN 				(GPIO_42)
#define LCD_MCU_D6_PIN 				(GPIO_41)
#define LCD_MCU_D7_PIN 				(GPIO_40)
#define LCD_MCU_RDX_PIN 		 	(GPIO_23)
#define LCD_MCU_WRX_PIN 		 	(GPIO_22)
#define LCD_MCU_RSX_PIN 		 	(GPIO_21)
#define LCD_MCU_RESET_PIN 		 	(GPIO_20)
#define LCD_MCU_CSX_PIN 		 	(GPIO_19)

#define LCD_MCU_D0_FUNC 			(GPIO_DEV_LCD_RGB0)
#define LCD_MCU_D1_FUNC 			(GPIO_DEV_LCD_RGB1)
#define LCD_MCU_D2_FUNC 			(GPIO_DEV_LCD_RGB2)
#define LCD_MCU_D3_FUNC 			(GPIO_DEV_LCD_RGB3)
#define LCD_MCU_D4_FUNC 			(GPIO_DEV_LCD_RGB4)
#define LCD_MCU_D5_FUNC 			(GPIO_DEV_LCD_RGB5)
#define LCD_MCU_D6_FUNC 			(GPIO_DEV_LCD_RGB6)
#define LCD_MCU_D7_FUNC 			(GPIO_DEV_LCD_RGB7)
#define LCD_MCU_RDX_FUNC 		 	(GPIO_DEV_LCD_RGB11)
#define LCD_MCU_WRX_FUNC 		 	(GPIO_DEV_LCD_RGB12)
#define LCD_MCU_RSX_FUNC 		 	(GPIO_DEV_LCD_RGB13)
#define LCD_MCU_RESET_FUNC 		 	(GPIO_DEV_LCD_RGB14)
#define LCD_MCU_CSX_FUNC 		 	(GPIO_DEV_LCD_RGB15)

#define GPIO_CTRL_LDO_OUTPUT_HIGH_MAP  \
{\
	/* GPIO_2, */\
	/* GPIO_28, */\
}

#define GPIO_CTRL_LDO_OUTPUT_LOW_MAP  \
{\
	/* GPIO_4, */\
	/* GPIO_26, */\
}
/*---multi modules use one gpio to control different ldo---*/
#define GPIO_CTRL_LDO_MAP  \
{\
	{GPIO_8,  GPIO_OUTPUT_STATE_LOW} \
}

#ifdef __cplusplus
}
#endif
