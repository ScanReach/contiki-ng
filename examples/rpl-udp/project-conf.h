/*
 * project-conf.h
 *
 *  Created on: 30. jan. 2019
 *      Author: MariusNorvollSletten
 */

#ifndef _PROJECT_CONF_H_
#define _PROJECT_CONF_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define CSMA_CONF_LLSEC_DEFAULT_KEY0       {0x53, 0x52, 0x54, 0x54, 0x45, 0x53, 0x54, 0x4f, 0x4e, 0x4c, 0x59, 0x32, \
                                            0x30, 0x32, 0x30, 0x21}
#define PROPMODE_BAND_SELECT_CHANNEL                        0
#define IEEE802154_CONF_PANID                               0xabcd

// #define TI_UART_CONF_UART0_ENABLE                           1
#define TI_UART_CONF_UART1_ENABLE                           1
#define TI_UART_CONF_BAUD_RATE_BLE                          1000000

#define  WATCHDOG_CONF_DISABLE 0

#define MEESHNODE 1 // TODO: Get this define via the build system (prefereably connected to the board definition)
#if MEESHNODE // The build is for the meshnode
#define SET_CCFG_MODE_CONF_XOSC_CAP_MOD 0x0
#define SET_CCFG_MODE_CONF_XOSC_CAPARRAY_DELTA 5
#else // The build is for launchpad
#define SET_CCFG_MODE_CONF_XOSC_CAP_MOD 0
#define SET_CCFG_MODE_CONF_XOSC_CAPARRAY_DELTA -63
#endif

#define LOG_LEVEL_SRT                          LOG_LEVEL_NONE
#define LOG_LEVEL_SRT_OTA                      LOG_LEVEL_NONE
#define LOG_LEVEL_SRT_ROOT_UART                LOG_LEVEL_NONE
#define LOG_LEVEL_SRT_RPL_DIRECTED_MESSAGES    LOG_LEVEL_NONE
#define LOG_CONF_LEVEL_IPV6                    LOG_LEVEL_NONE
#define LOG_CONF_LEVEL_RPL                     LOG_LEVEL_NONE
#define LOG_CONF_LEVEL_6LOWPAN                 LOG_LEVEL_NONE
#define LOG_CONF_LEVEL_MAC                     LOG_LEVEL_NONE
//#define LOG_CONF_LEVEL_FRAMER                  LOG_LEVEL_NONE
#define LOG_LEVEL_RADIO                        LOG_LEVEL_NONE

#ifdef __cplusplus
}
#endif

#endif /*_PROJECT_CONF_H_ */
