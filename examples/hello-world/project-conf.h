/*
 * Copyright (c) 2010, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

#define CSMA_CONF_LLSEC_DEFAULT_KEY0       {0x53, 0x52, 0x54, 0x54, 0x45, 0x53, 0x54, 0x4f, 0x4e, 0x4c, 0x59, 0x32, \
                                            0x30, 0x32, 0x30, 0x21}
#define PROPMODE_BAND_SELECT_CHANNEL                        0
#define IEEE802154_CONF_PANID                               0xabcd


#define  WATCHDOG_CONF_DISABLE 0

#define MEESHNODE 0 // TODO: Get this define via the build system (prefereably connected to the board definition)
#if MEESHNODE
#define SET_CCFG_MODE_CONF_XOSC_CAP_MOD 0x0
#define SET_CCFG_MODE_CONF_XOSC_CAPARRAY_DELTA 5
#else
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

#endif /* PROJECT_CONF_H_ */
