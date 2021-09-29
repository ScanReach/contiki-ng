/*
 * Copyright (c) 2017-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __BOARD_H
#define __BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drivers/Board.h>
#include "CC1352P_MESHNODE.h"

#define Board_CC1352P_MESHNODE
#define BOARD_STRING            "SRT CC1352P Mesh Node"

#define Board_initGeneral()      Board_init()  /* deprecated */

/* These #defines allow us to reuse TI-RTOS across other device families */

#define Board_ADC0              CC1352P_MESHNODE_ADC6
#define Board_ADC1              CC1352P_MESHNODE_ADC7
#define Board_ADC_VCC_IN        CC1352P_MESHNODE_ADC6
#define Board_ADC_NTC           CC1352P_MESHNODE_ADC7

#define Board_ADCBUF0           CC1352P_MESHNODE_ADCBUF0
#define Board_ADCBUF0CHANNEL0   CC1352P_MESHNODE_ADCBUF0CHANNEL0
#define Board_ADCBUF0CHANNEL1   CC1352P_MESHNODE_ADCBUF0CHANNEL1

#define Board_CRYPTO0           CC1352P_MESHNODE_CRYPTO0
#define Board_ECDH0             CC1352P_MESHNODE_ECDH0
#define Board_ECDSA0            CC1352P_MESHNODE_ECDSA0
#define Board_ECJPAKE0          CC1352P_MESHNODE_ECJPAKE0
#define Board_AESCCM0           CC1352P_MESHNODE_AESCCM0
#define Board_AESGCM0           CC1352P_MESHNODE_AESGCM0
#define Board_AESCBC0           CC1352P_MESHNODE_AESCBC0
#define Board_AESCTR0           CC1352P_MESHNODE_AESCTR0
#define Board_AESECB0           CC1352P_MESHNODE_AESECB0
#define Board_AESCTRDRBG0       CC1352P_MESHNODE_AESCTRDRBG0
#define Board_SHA20             CC1352P_MESHNODE_SHA20
#define Board_TRNG0             CC1352P_MESHNODE_TRNG0

#define Board_DIO_USBCONNECTED    CC1352P_MESHNODE_DIO_USBCONNECTED
#define Board_DIO_ANTSEL_SUBGHZ   CC1352P_MESHNODE_DIO_ANTSEL_SUBGHZ
#define Board_DIO_ANTSEL_EXT      CC1352P_MESHNODE_DIO_ANTSEL_EXT
#define Board_DIO_ANTSEL_24GHZ    CC1352P_MESHNODE_DIO_ANTSEL_24GHZ
#define Board_DIO_CONNECT_BATT    CC1352P_MESHNODE_DIO_CONNECT_BATT
#define Board_DIO_CHARGER_EN      CC1352P_MESHNODE_DIO_CHARGER_EN
#define Board_DIO_CHARGER_STAT    CC1352P_MESHNODE_DIO_CHARGER_STAT
#define Board_DIO_BLE_GPIO        CC1352P_MESHNODE_DIO_BLE_GPIO
#define Board_DIO_FLASH_RESETn    CC1352P_MESHNODE_DIO_FLASH_RESETn
#define Board_DIO_FLASH_WPn       CC1352P_MESHNODE_DIO_FLASH_WPn
#define Board_DIO_ADC_VCC_IN      CC1352P_MESHNODE_DIO_ADC_VCC_IN
#define Board_DIO_ADC_NTC         CC1352P_MESHNODE_DIO_ADC_NTC

#define Board_USB_CONNECTED             1
#define Board_USB_DISCONNECTED          0
#define Board_ANTSEL_PATH_SELECT        1
#define Board_ANTSEL_PATH_DESELECT      0
#define Board_CONNECT_BATT_CONNECT      1
#define Board_CONNECT_BATT_DISONNECT    0
#define Board_CHARGER_ENABLE            1
#define Board_CHARGER_DISABLE           0
#define Board_CHARGER_STAT_NOT_CHARGING 1
#define Board_CHARGER_STAT_CHARGING     0
#define Board_FLASH_RESETn_ENABLE       0
#define Board_FLASH_RESETn_DISABLE      1
#define Board_FLASH_WPn_ENABLE          0
#define Board_FLASH_WPn_DISABLE         1
#define Board_FLASH_CSN_SELECT          0
#define Board_FLASH_CSN_UNSELECT        1

#define Board_DIO12             CC1352P_MESHNODE_DIO12
#define Board_DIO15             CC1352P_MESHNODE_DIO15
#define Board_DIO16_TDO         CC1352P_MESHNODE_DIO16_TDO
#define Board_DIO17_TDI         CC1352P_MESHNODE_DIO17_TDI
#define Board_DIO21             CC1352P_MESHNODE_DIO21
#define Board_DIO22             CC1352P_MESHNODE_DIO22

#define Board_DIO23_ANALOG      CC1352P_MESHNODE_DIO23_ANALOG
#define Board_DIO24_ANALOG      CC1352P_MESHNODE_DIO24_ANALOG
#define Board_DIO25_ANALOG      CC1352P_MESHNODE_DIO25_ANALOG
#define Board_DIO26_ANALOG      CC1352P_MESHNODE_DIO26_ANALOG
#define Board_DIO27_ANALOG      CC1352P_MESHNODE_DIO27_ANALOG
#define Board_DIO28_ANALOG      CC1352P_MESHNODE_DIO28_ANALOG
#define Board_DIO29_ANALOG      CC1352P_MESHNODE_DIO29_ANALOG
#define Board_DIO30_RFSW        CC1352P_MESHNODE_DIO30_RF_SUB1GHZ

/*
 *  Board_RF_SUB1GHZ, Board_RF_HIGH_PA, and Board_RF_24GHZ are the names
 *  generated by SysConfig. Define them here so that the RF callback function
 *  can reference them.
 */
#define Board_RF_24GHZ          CC1352P_MESHNODE_DIO28_RF_24GHZ
#define Board_RF_HIGH_PA        CC1352P_MESHNODE_DIO29_RF_HIGH_PA
#define Board_RF_SUB1GHZ        CC1352P_MESHNODE_DIO30_RF_SUB1GHZ

#define Board_GPIO_BUTTON0      CC1352P_MESHNODE_GPIO_S1
#define Board_GPIO_BUTTON1      CC1352P_MESHNODE_GPIO_S2
#define Board_GPIO_BTN1         CC1352P_MESHNODE_GPIO_S1
#define Board_GPIO_BTN2         CC1352P_MESHNODE_GPIO_S2
#define Board_GPIO_LED0         CC1352P_MESHNODE_GPIO_LED_RED
#define Board_GPIO_LED1         CC1352P_MESHNODE_GPIO_LED_GREEN
#define Board_GPIO_LED2         CC1352P_MESHNODE_GPIO_LED_RED
#define Board_GPIO_RLED         CC1352P_MESHNODE_GPIO_LED_RED
#define Board_GPIO_GLED         CC1352P_MESHNODE_GPIO_LED_GREEN
#define Board_GPIO_LED_ON       CC1352P_MESHNODE_GPIO_LED_ON
#define Board_GPIO_LED_OFF      CC1352P_MESHNODE_GPIO_LED_OFF

#define Board_GPTIMER0A         CC1352P_MESHNODE_GPTIMER0A
#define Board_GPTIMER0B         CC1352P_MESHNODE_GPTIMER0B
#define Board_GPTIMER1A         CC1352P_MESHNODE_GPTIMER1A
#define Board_GPTIMER1B         CC1352P_MESHNODE_GPTIMER1B
#define Board_GPTIMER2A         CC1352P_MESHNODE_GPTIMER2A
#define Board_GPTIMER2B         CC1352P_MESHNODE_GPTIMER2B
#define Board_GPTIMER3A         CC1352P_MESHNODE_GPTIMER3A
#define Board_GPTIMER3B         CC1352P_MESHNODE_GPTIMER3B

#define Board_I2C0              CC1352P_MESHNODE_I2C0
#define Board_I2C_TMP           Board_I2C0

#define Board_I2S0              CC1352P_MESHNODE_I2S0
#define Board_I2S_ADO           CC1352P_MESHNODE_I2S_ADO
#define Board_I2S_ADI           CC1352P_MESHNODE_I2S_ADI
#define Board_I2S_BCLK          CC1352P_MESHNODE_I2S_BCLK
#define Board_I2S_MCLK          CC1352P_MESHNODE_I2S_MCLK
#define Board_I2S_WCLK          CC1352P_MESHNODE_I2S_WCLK

#define Board_NVSINTERNAL       CC1352P_MESHNODE_NVSCC26XX0
#define Board_NVSEXTERNAL       CC1352P_MESHNODE_NVSSPI25X0

#define Board_PIN_BUTTON0       CC1352P_MESHNODE_PIN_BTN1
#define Board_BTN_UNPRESSED 1
#define Board_BTN_PRESSED 0

#define Board_PIN_BUTTON1       CC1352P_MESHNODE_PIN_BTN2
#define Board_PIN_BTN1          CC1352P_MESHNODE_PIN_BTN1
#define Board_PIN_BTN2          CC1352P_MESHNODE_PIN_BTN2
#define Board_PIN_LED0          CC1352P_MESHNODE_PIN_RLED
#define Board_PIN_LED1          CC1352P_MESHNODE_PIN_GLED
#define Board_PIN_LED2          CC1352P_MESHNODE_PIN_RLED
#define Board_PIN_RLED          CC1352P_MESHNODE_PIN_RLED
#define Board_PIN_GLED          CC1352P_MESHNODE_PIN_GLED

#define Board_PWM0              CC1352P_MESHNODE_PWM0
#define Board_PWM1              CC1352P_MESHNODE_PWM1
#define Board_PWM2              CC1352P_MESHNODE_PWM2
#define Board_PWM3              CC1352P_MESHNODE_PWM3
#define Board_PWM4              CC1352P_MESHNODE_PWM4
#define Board_PWM5              CC1352P_MESHNODE_PWM5
#define Board_PWM6              CC1352P_MESHNODE_PWM6
#define Board_PWM7              CC1352P_MESHNODE_PWM7

#define Board_SD0               CC1352P_MESHNODE_SDSPI0

#define Board_SPI0              CC1352P_MESHNODE_SPI0
#define Board_SPI0_MISO         CC1352P_MESHNODE_SPI0_MISO
#define Board_SPI0_MOSI         CC1352P_MESHNODE_SPI0_MOSI
#define Board_SPI0_CLK          CC1352P_MESHNODE_SPI0_CLK
#define Board_SPI0_CSN          CC1352P_MESHNODE_SPI0_CSN
#define Board_SPI1              CC1352P_MESHNODE_SPI1
#define Board_SPI1_MISO         CC1352P_MESHNODE_SPI1_MISO
#define Board_SPI1_MOSI         CC1352P_MESHNODE_SPI1_MOSI
#define Board_SPI1_CLK          CC1352P_MESHNODE_SPI1_CLK
#define Board_SPI1_CSN          CC1352P_MESHNODE_SPI1_CSN
#define Board_SPI_FLASH_CS      CC1352P_MESHNODE_SPI_FLASH_CS
#define Board_FLASH_CS_ON       0
#define Board_FLASH_CS_OFF      1

#define Board_SPI_MASTER        CC1352P_MESHNODE_SPI0
#define Board_SPI_SLAVE         CC1352P_MESHNODE_SPI0
#define Board_SPI_MASTER_READY  CC1352P_MESHNODE_SPI_MASTER_READY
#define Board_SPI_SLAVE_READY   CC1352P_MESHNODE_SPI_SLAVE_READY

#define Board_UART0             CC1352P_MESHNODE_UART0
#define Board_UART1             CC1352P_MESHNODE_UART1

#define Board_WATCHDOG0         CC1352P_MESHNODE_WATCHDOG0

#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H */
