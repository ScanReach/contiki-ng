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

/*
 *  ====================== CC1352P_MESHNODE.c ===================================
 *  This file is responsible for setting up the board specific items for the
 *  CC1352P_MESHNODE board.
 */

#include "CC1352P_MESHNODE.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/ioc.h)
#include DeviceFamily_constructPath(driverlib/udma.h)
#include DeviceFamily_constructPath(inc/hw_ints.h)
#include DeviceFamily_constructPath(inc/hw_memmap.h)

#include <ti/drivers/ADCBuf.h>
#include <ti/drivers/adcbuf/ADCBufCC26X2.h>

ADCBufCC26X2_Object adcBufCC26xxObjects[CC1352P_MESHNODE_ADCBUFCOUNT];

/*
 *  This table converts a virtual adc channel into a dio and internal analogue
 *  input signal. This table is necessary for the functioning of the adcBuf
 *  driver. Comment out unused entries to save flash. Dio and internal signal
 *  pairs are hardwired. Do not remap them in the table. You may reorder entire
 *  entries. The mapping of dio and internal signals is package dependent.
 */
const ADCBufCC26X2_AdcChannelLutEntry ADCBufCC26X2_adcChannelLut[CC1352P_MESHNODE_ADCBUF0CHANNELCOUNT] = {
    {CC1352P_MESHNODE_DIO23_ANALOG, ADC_COMPB_IN_AUXIO7},
    {CC1352P_MESHNODE_DIO24_ANALOG, ADC_COMPB_IN_AUXIO6},
    {CC1352P_MESHNODE_DIO25_ANALOG, ADC_COMPB_IN_AUXIO5},
    {CC1352P_MESHNODE_DIO26_ANALOG, ADC_COMPB_IN_AUXIO4},
    {CC1352P_MESHNODE_DIO27_ANALOG, ADC_COMPB_IN_AUXIO3},
    {PIN_UNASSIGNED, ADC_COMPB_IN_VDDS},
    {PIN_UNASSIGNED, ADC_COMPB_IN_DCOUPL},
    {PIN_UNASSIGNED, ADC_COMPB_IN_VSS},
};

const ADCBufCC26X2_HWAttrs adcBufCC26xxHWAttrs[CC1352P_MESHNODE_ADCBUFCOUNT] = {
    {
        .intPriority       = ~0,
        .swiPriority       = 0,
        .adcChannelLut     = ADCBufCC26X2_adcChannelLut,
        .gpTimerUnit       = CC1352P_MESHNODE_GPTIMER0A,
     }
};

const ADCBuf_Config ADCBuf_config[CC1352P_MESHNODE_ADCBUFCOUNT] = {
    {
        &ADCBufCC26X2_fxnTable,
        &adcBufCC26xxObjects[CC1352P_MESHNODE_ADCBUF0],
        &adcBufCC26xxHWAttrs[CC1352P_MESHNODE_ADCBUF0]
    },
};

const uint_least8_t ADCBuf_count = CC1352P_MESHNODE_ADCBUFCOUNT;

/*
 *  =============================== ADC ===============================
 */
#include <ti/drivers/ADC.h>
#include <ti/drivers/adc/ADCCC26XX.h>

ADCCC26XX_Object adcCC26xxObjects[CC1352P_MESHNODE_ADCCOUNT];

const ADCCC26XX_HWAttrs adcCC26xxHWAttrs[CC1352P_MESHNODE_ADCCOUNT] = {
    {
        .adcDIO              = CC1352P_MESHNODE_DIO23_ANALOG,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO7,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = CC1352P_MESHNODE_DIO24_ANALOG,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO6,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = CC1352P_MESHNODE_DIO25_ANALOG,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO5,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = CC1352P_MESHNODE_DIO26_ANALOG,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO4,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = CC1352P_MESHNODE_DIO27_ANALOG,
        .adcCompBInput       = ADC_COMPB_IN_AUXIO3,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_DCOUPL,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_VSS,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    },
    {
        .adcDIO              = PIN_UNASSIGNED,
        .adcCompBInput       = ADC_COMPB_IN_VDDS,
        .refSource           = ADCCC26XX_FIXED_REFERENCE,
        .samplingDuration    = ADCCC26XX_SAMPLING_DURATION_2P7_US,
        .inputScalingEnabled = true,
        .triggerSource       = ADCCC26XX_TRIGGER_MANUAL,
        .returnAdjustedVal   = false
    }
};

const ADC_Config ADC_config[CC1352P_MESHNODE_ADCCOUNT] = {
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADC0], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADC0]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADC1], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADC1]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADC2], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADC2]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADC3], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADC3]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADC4], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADC4]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADCDCOUPL], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADCDCOUPL]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADCVSS], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADCVSS]},
    {&ADCCC26XX_fxnTable, &adcCC26xxObjects[CC1352P_MESHNODE_ADCVDDS], &adcCC26xxHWAttrs[CC1352P_MESHNODE_ADCVDDS]},
};

const uint_least8_t ADC_count = CC1352P_MESHNODE_ADCCOUNT;

/*
 *  =============================== ECDH ===============================
 */
#include <ti/drivers/ECDH.h>
#include <ti/drivers/ecdh/ECDHCC26X2.h>

ECDHCC26X2_Object ecdhCC26X2Objects[CC1352P_MESHNODE_ECDHCOUNT];

const ECDHCC26X2_HWAttrs ecdhCC26X2HWAttrs[CC1352P_MESHNODE_ECDHCOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const ECDH_Config ECDH_config[CC1352P_MESHNODE_ECDHCOUNT] = {
    {
         .object  = &ecdhCC26X2Objects[CC1352P_MESHNODE_ECDH0],
         .hwAttrs = &ecdhCC26X2HWAttrs[CC1352P_MESHNODE_ECDH0]
    },
};

const uint_least8_t ECDH_count = CC1352P_MESHNODE_ECDHCOUNT;

/*
 *  =============================== ECDSA ===============================
 */
#include <ti/drivers/ECDSA.h>
#include <ti/drivers/ecdsa/ECDSACC26X2.h>

ECDSACC26X2_Object ecdsaCC26X2Objects[CC1352P_MESHNODE_ECDSACOUNT];

const ECDSACC26X2_HWAttrs ecdsaCC26X2HWAttrs[CC1352P_MESHNODE_ECDSACOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const ECDSA_Config ECDSA_config[CC1352P_MESHNODE_ECDSACOUNT] = {
    {
         .object  = &ecdsaCC26X2Objects[CC1352P_MESHNODE_ECDSA0],
         .hwAttrs = &ecdsaCC26X2HWAttrs[CC1352P_MESHNODE_ECDSA0]
    },
};

const uint_least8_t ECDSA_count = CC1352P_MESHNODE_ECDSACOUNT;

/*
 *  =============================== ECJPAKE ===============================
 */
#include <ti/drivers/ECJPAKE.h>
#include <ti/drivers/ecjpake/ECJPAKECC26X2.h>

ECJPAKECC26X2_Object ecjpakeCC26X2Objects[CC1352P_MESHNODE_ECJPAKECOUNT];

const ECJPAKECC26X2_HWAttrs ecjpakeCC26X2HWAttrs[CC1352P_MESHNODE_ECJPAKECOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const ECJPAKE_Config ECJPAKE_config[CC1352P_MESHNODE_ECJPAKECOUNT] = {
    {
         .object  = &ecjpakeCC26X2Objects[CC1352P_MESHNODE_ECJPAKE0],
         .hwAttrs = &ecjpakeCC26X2HWAttrs[CC1352P_MESHNODE_ECJPAKE0]
    },
};

const uint_least8_t ECJPAKE_count = CC1352P_MESHNODE_ECJPAKECOUNT;


/*
 *  =============================== SHA2 ===============================
 */
#include <ti/drivers/SHA2.h>
#include <ti/drivers/sha2/SHA2CC26X2.h>

SHA2CC26X2_Object sha2CC26X2Objects[CC1352P_MESHNODE_SHA2COUNT];

const SHA2CC26X2_HWAttrs sha2CC26X2HWAttrs[CC1352P_MESHNODE_SHA2COUNT] = {
    {
        .intPriority       = ~0,
    }
};

const SHA2_Config SHA2_config[CC1352P_MESHNODE_SHA2COUNT] = {
    {
         .object  = &sha2CC26X2Objects[CC1352P_MESHNODE_SHA20],
         .hwAttrs = &sha2CC26X2HWAttrs[CC1352P_MESHNODE_SHA20]
    },
};

const uint_least8_t SHA2_count = CC1352P_MESHNODE_SHA2COUNT;

/*
 *  =============================== AESCCM ===============================
 */
#include <ti/drivers/AESCCM.h>
#include <ti/drivers/aesccm/AESCCMCC26XX.h>

AESCCMCC26XX_Object aesccmCC26XXObjects[CC1352P_MESHNODE_AESCCMCOUNT];

const AESCCMCC26XX_HWAttrs aesccmCC26XXHWAttrs[CC1352P_MESHNODE_AESCCMCOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const AESCCM_Config AESCCM_config[CC1352P_MESHNODE_AESCCMCOUNT] = {
    {
         .object  = &aesccmCC26XXObjects[CC1352P_MESHNODE_AESCCM0],
         .hwAttrs = &aesccmCC26XXHWAttrs[CC1352P_MESHNODE_AESCCM0]
    },
};

const uint_least8_t AESCCM_count = CC1352P_MESHNODE_AESCCMCOUNT;

/*
 *  =============================== AESGCM ===============================
 */
#include <ti/drivers/AESGCM.h>
#include <ti/drivers/aesgcm/AESGCMCC26XX.h>

AESGCMCC26XX_Object aesgcmCC26XXObjects[CC1352P_MESHNODE_AESGCMCOUNT];

const AESGCMCC26XX_HWAttrs aesgcmCC26XXHWAttrs[CC1352P_MESHNODE_AESGCMCOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const AESGCM_Config AESGCM_config[CC1352P_MESHNODE_AESGCMCOUNT] = {
    {
         .object  = &aesgcmCC26XXObjects[CC1352P_MESHNODE_AESGCM0],
         .hwAttrs = &aesgcmCC26XXHWAttrs[CC1352P_MESHNODE_AESGCM0]
    },
};

const uint_least8_t AESGCM_count = CC1352P_MESHNODE_AESGCMCOUNT;

/*
 *  =============================== AESCBC ===============================
 */
#include <ti/drivers/AESCBC.h>
#include <ti/drivers/aescbc/AESCBCCC26XX.h>

AESCBCCC26XX_Object aescbcCC26XXObjects[CC1352P_MESHNODE_AESCBCCOUNT];

const AESCBCCC26XX_HWAttrs aescbcCC26XXHWAttrs[CC1352P_MESHNODE_AESCBCCOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const AESCBC_Config AESCBC_config[CC1352P_MESHNODE_AESCBCCOUNT] = {
    {
         .object  = &aescbcCC26XXObjects[CC1352P_MESHNODE_AESCBC0],
         .hwAttrs = &aescbcCC26XXHWAttrs[CC1352P_MESHNODE_AESCBC0]
    },
};

const uint_least8_t AESCBC_count = CC1352P_MESHNODE_AESCBCCOUNT;

/*
 *  =============================== AESCTR ===============================
 */
#include <ti/drivers/AESCTR.h>
#include <ti/drivers/aesctr/AESCTRCC26XX.h>

AESCTRCC26XX_Object aesctrCC26XXObjects[CC1352P_MESHNODE_AESCTRCOUNT];

const AESCTRCC26XX_HWAttrs aesctrCC26XXHWAttrs[CC1352P_MESHNODE_AESCTRCOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const AESCTR_Config AESCTR_config[CC1352P_MESHNODE_AESCTRCOUNT] = {
    {
         .object  = &aesctrCC26XXObjects[CC1352P_MESHNODE_AESCTR0],
         .hwAttrs = &aesctrCC26XXHWAttrs[CC1352P_MESHNODE_AESCTR0]
    },
};

const uint_least8_t AESCTR_count = CC1352P_MESHNODE_AESCTRCOUNT;

/*
 *  =============================== AESECB ===============================
 */
#include <ti/drivers/AESECB.h>
#include <ti/drivers/aesecb/AESECBCC26XX.h>

AESECBCC26XX_Object aesecbCC26XXObjects[CC1352P_MESHNODE_AESECBCOUNT];

const AESECBCC26XX_HWAttrs aesecbCC26XXHWAttrs[CC1352P_MESHNODE_AESECBCOUNT] = {
    {
        .intPriority       = ~0,
    }
};

const AESECB_Config AESECB_config[CC1352P_MESHNODE_AESECBCOUNT] = {
    {
         .object  = &aesecbCC26XXObjects[CC1352P_MESHNODE_AESECB0],
         .hwAttrs = &aesecbCC26XXHWAttrs[CC1352P_MESHNODE_AESECB0]
    },
};

const uint_least8_t AESECB_count = CC1352P_MESHNODE_AESECBCOUNT;

/*
 *  =============================== AESCTRDRBG ===============================
 */
#include <ti/drivers/AESCTRDRBG.h>
#include <ti/drivers/aesctrdrbg/AESCTRDRBGXX.h>

AESCTRDRBGXX_Object aesctrdrbgXXObjects[CC1352P_MESHNODE_AESCTRDRBGCOUNT];

const AESCTRDRBGXX_HWAttrs aesctrdrbgXXHWAttrs[CC1352P_MESHNODE_AESCTRDRBGCOUNT] = {
    {
        .aesctrIndex       = CC1352P_MESHNODE_AESCTR0,
    }
};

const AESCTRDRBG_Config AESCTRDRBG_config[CC1352P_MESHNODE_AESCTRDRBGCOUNT] = {
    {
         .object  = &aesctrdrbgXXObjects[CC1352P_MESHNODE_AESCTRDRBG0],
         .hwAttrs = &aesctrdrbgXXHWAttrs[CC1352P_MESHNODE_AESCTRDRBG0]
    },
};

const uint_least8_t AESCTRDRBG_count = CC1352P_MESHNODE_AESCTRDRBGCOUNT;

/*
 *  =============================== TRNG ===============================
 */
#include <ti/drivers/TRNG.h>
#include <ti/drivers/trng/TRNGCC26XX.h>

TRNGCC26XX_Object trngCC26XXObjects[CC1352P_MESHNODE_TRNGCOUNT];

const TRNGCC26XX_HWAttrs trngCC26X2HWAttrs[CC1352P_MESHNODE_TRNGCOUNT] = {
    {
        .intPriority       = ~0,
        .swiPriority       = 0,
        .samplesPerCycle   = 240000,
    }
};

const TRNG_Config TRNG_config[CC1352P_MESHNODE_TRNGCOUNT] = {
    {
         .object  = &trngCC26XXObjects[CC1352P_MESHNODE_TRNG0],
         .hwAttrs = &trngCC26X2HWAttrs[CC1352P_MESHNODE_TRNG0]
    },
};

const uint_least8_t TRNG_count = CC1352P_MESHNODE_TRNGCOUNT;

/*
 *  =============================== GPIO ===============================
 */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOCC26XX.h>

/*
 * Array of Pin configurations
 * NOTE: The order of the pin configurations must coincide with what was
 *       defined in CC1352P_MESHNODE.h
 * NOTE: Pins not used for interrupts should be placed at the end of the
 *       array. Callback entries can be omitted from callbacks array to
 *       reduce memory usage.
 */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Input pins */
    GPIOCC26XX_DIO_15 | GPIO_DO_NOT_CONFIG,  /* Button 0 */
    GPIOCC26XX_DIO_14 | GPIO_DO_NOT_CONFIG,  /* Button 1 */

    GPIOCC26XX_DIO_15 | GPIO_DO_NOT_CONFIG,  /* CC1352P_MESHNODE_SPI_MASTER_READY */
    GPIOCC26XX_DIO_21 | GPIO_DO_NOT_CONFIG,  /* CC1352P_MESHNODE_SPI_SLAVE_READY */

    /* Output pins */
    GPIOCC26XX_DIO_06 | GPIO_DO_NOT_CONFIG,  /* Green LED */
    GPIOCC26XX_DIO_05 | GPIO_DO_NOT_CONFIG,  /* Red LED */

    /* SPI Flash CSN */
    GPIOCC26XX_DIO_20 | GPIO_DO_NOT_CONFIG,

    /* SD CS
     * On CC1352P LaunchPads, the default LaunchPad header for SD CS is not
     * connected. DIO_14 is mapped to the alternate SD CS pin on the SHARP128
     * BoosterPack. To enable the alternate SD CS BoosterPack pin, you need to
     * remove the SHARP128 R16 and solder it onto the unpopulated R17 instead.
     * When using the SD CS in this manner, BTN-2 is unavaillable since they
     * both map to DIO_14.
     * Alternatively, you can jumper wire the following on the LaunchPad:
     * J1.8 to DIO14
     */
    GPIOCC26XX_DIO_14 | GPIO_DO_NOT_CONFIG,
};

/*
 * Array of callback function pointers
 * NOTE: The order of the pin configurations must coincide with what was
 *       defined in CC1352P_LAUNCH.h
 * NOTE: Pins not used for interrupts can be omitted from callbacks array to
 *       reduce memory usage (if placed at end of gpioPinConfigs array).
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,  /* Button 0 */
    NULL,  /* Button 1 */
    NULL,  /* CC1352P_MESHNODE_SPI_MASTER_READY */
    NULL,  /* CC1352P_MESHNODE_SPI_SLAVE_READY */
};

const GPIOCC26XX_Config GPIOCC26XX_config = {
    .pinConfigs         = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks          = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = CC1352P_MESHNODE_GPIOCOUNT,
    .numberOfCallbacks  = sizeof(gpioCallbackFunctions)/sizeof(GPIO_CallbackFxn),
    .intPriority        = (~0)
};

/*
 *  =============================== GPTimer ===============================
 *  Remove unused entries to reduce flash usage both in Board.c and Board.h
 */
#include <ti/drivers/timer/GPTimerCC26XX.h>

GPTimerCC26XX_Object gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMERCOUNT];

const GPTimerCC26XX_HWAttrs gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMERPARTSCOUNT] = {
    { .baseAddr = GPT0_BASE, .intNum = INT_GPT0A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT0, .pinMux = GPT_PIN_0A, },
    { .baseAddr = GPT0_BASE, .intNum = INT_GPT0B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT0, .pinMux = GPT_PIN_0B, },
    { .baseAddr = GPT1_BASE, .intNum = INT_GPT1A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT1, .pinMux = GPT_PIN_1A, },
    { .baseAddr = GPT1_BASE, .intNum = INT_GPT1B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT1, .pinMux = GPT_PIN_1B, },
    { .baseAddr = GPT2_BASE, .intNum = INT_GPT2A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT2, .pinMux = GPT_PIN_2A, },
    { .baseAddr = GPT2_BASE, .intNum = INT_GPT2B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT2, .pinMux = GPT_PIN_2B, },
    { .baseAddr = GPT3_BASE, .intNum = INT_GPT3A, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT3, .pinMux = GPT_PIN_3A, },
    { .baseAddr = GPT3_BASE, .intNum = INT_GPT3B, .intPriority = (~0), .powerMngrId = PowerCC26XX_PERIPH_GPT3, .pinMux = GPT_PIN_3B, },
};

const GPTimerCC26XX_Config GPTimerCC26XX_config[CC1352P_MESHNODE_GPTIMERPARTSCOUNT] = {
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER0], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER0A], GPT_A },
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER0], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER0B], GPT_B },
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER1], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER1A], GPT_A },
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER1], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER1B], GPT_B },
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER2], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER2A], GPT_A },
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER2], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER2B], GPT_B },
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER3], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER3A], GPT_A },
    { &gptimerCC26XXObjects[CC1352P_MESHNODE_GPTIMER3], &gptimerCC26xxHWAttrs[CC1352P_MESHNODE_GPTIMER3B], GPT_B },
};

/*
 *  =============================== I2C ===============================
*/
#include <ti/drivers/I2C.h>
#include <ti/drivers/i2c/I2CCC26XX.h>

#if TI_I2C_CONF_ENABLE

I2CCC26XX_Object i2cCC26xxObjects[CC1352P_MESHNODE_I2CCOUNT];

const I2CCC26XX_HWAttrsV1 i2cCC26xxHWAttrs[CC1352P_MESHNODE_I2CCOUNT] = {
#if TI_I2C_CONF_I2C0_ENABLE
    {
        .baseAddr    = I2C0_BASE,
        .powerMngrId = PowerCC26XX_PERIPH_I2C0,
        .intNum      = INT_I2C_IRQ,
        .intPriority = ~0,
        .swiPriority = 0,
        .sdaPin      = CC1352P_MESHNODE_I2C0_SDA0,
        .sclPin      = CC1352P_MESHNODE_I2C0_SCL0,
    },
#endif
};

const I2C_Config I2C_config[CC1352P_MESHNODE_I2CCOUNT] = {
#if TI_I2C_CONF_I2C0_ENABLE
    {
        .fxnTablePtr = &I2CCC26XX_fxnTable,
        .object      = &i2cCC26xxObjects[CC1352P_MESHNODE_I2C0],
        .hwAttrs     = &i2cCC26xxHWAttrs[CC1352P_MESHNODE_I2C0]
    },
#endif
};

const uint_least8_t I2C_count = CC1352P_MESHNODE_I2CCOUNT;

#endif /* TI_I2C_CONF_ENABLE */

/*
 *  =============================== I2S ===============================
*/
#include <ti/drivers/I2S.h>
#include <ti/drivers/i2s/I2SCC26XX.h>

I2SCC26XX_Object i2sCC26XXObjects[CC1352P_MESHNODE_I2SCOUNT];

const I2SCC26XX_HWAttrs i2sCC26XXHWAttrs[CC1352P_MESHNODE_I2SCOUNT] = {
    {
        .pinSD1      =  CC1352P_MESHNODE_I2S_ADI,
        .pinSD0      =  CC1352P_MESHNODE_I2S_ADO,
        .pinSCK      =  CC1352P_MESHNODE_I2S_BCLK,
        .pinMCLK     =  CC1352P_MESHNODE_I2S_MCLK,
        .pinWS       =  CC1352P_MESHNODE_I2S_WCLK,
        .intPriority = ~0,
    }
};

const I2S_Config I2S_config[CC1352P_MESHNODE_I2SCOUNT] = {
    {
        .object      = &i2sCC26XXObjects[CC1352P_MESHNODE_I2S0],
        .hwAttrs     = &i2sCC26XXHWAttrs[CC1352P_MESHNODE_I2S0]
    },
};

const uint_least8_t I2S_count = CC1352P_MESHNODE_I2SCOUNT;

/*
 *  =============================== NVS ===============================
 */
#include <ti/drivers/NVS.h>
#include <ti/drivers/nvs/NVSSPI25X.h>
#include <ti/drivers/nvs/NVSCC26XX.h>

#define NVS_REGIONS_BASE 0x50000
#define SECTORSIZE       0x2000
#define REGIONSIZE       (SECTORSIZE * 2)

#if TI_NVS_CONF_ENABLE

#if TI_NVS_CONF_NVS_INTERNAL_ENABLE

/*
 * Reserve flash sectors for NVS driver use by placing an uninitialized byte
 * array at the desired flash address.
 */
#if defined(__TI_COMPILER_VERSION__)

/*
 * Place uninitialized array at NVS_REGIONS_BASE
 */
#pragma LOCATION(flashBuf, NVS_REGIONS_BASE);
#pragma NOINIT(flashBuf);
static char flashBuf[REGIONSIZE];

#elif defined(__IAR_SYSTEMS_ICC__)

/*
 * Place uninitialized array at NVS_REGIONS_BASE
 */
static __no_init char flashBuf[REGIONSIZE] @ NVS_REGIONS_BASE;

#elif defined(__GNUC__)

/*
 * Place the flash buffers in the .nvs section created in the gcc linker file.
 * The .nvs section enforces alignment on a sector boundary but may
 * be placed anywhere in flash memory.  If desired the .nvs section can be set
 * to a fixed address by changing the following in the gcc linker file:
 *
 * .nvs (FIXED_FLASH_ADDR) (NOLOAD) : AT (FIXED_FLASH_ADDR) {
 *      *(.nvs)
 * } > REGION_TEXT
 */
__attribute__ ((section (".nvs")))
static char flashBuf[REGIONSIZE];

#endif

/* Allocate objects for NVS Internal Regions */
NVSCC26XX_Object nvsCC26xxObjects[1];

/* Hardware attributes for NVS Internal Regions */
const NVSCC26XX_HWAttrs nvsCC26xxHWAttrs[1] = {
    {
        .regionBase = (void *)flashBuf,
        .regionSize = REGIONSIZE,
    },
};

#endif /* TI_NVS_CONF_NVS_INTERNAL_ENABLE */

#if TI_NVS_CONF_NVS_EXTERNAL_ENABLE

#define SPISECTORSIZE    0x1000
#define SPIREGIONSIZE    (SPISECTORSIZE * 32)
#define VERIFYBUFSIZE    64

static uint8_t verifyBuf[VERIFYBUFSIZE];

/* Allocate objects for NVS External Regions */
NVSSPI25X_Object nvsSPI25XObjects[1];

/* Hardware attributes for NVS External Regions */
const NVSSPI25X_HWAttrs nvsSPI25XHWAttrs[1] = {
    {
        .regionBaseOffset = 0,
        .regionSize = SPIREGIONSIZE,
        .sectorSize = SPISECTORSIZE,
        .verifyBuf = verifyBuf,
        .verifyBufSize = VERIFYBUFSIZE,
        .spiHandle = NULL,
        .spiIndex = 0,
        .spiBitRate = 4000000,
        .spiCsnGpioIndex = CC1352P_MESHNODE_GPIO_SPI_FLASH_CS,
        .statusPollDelayUs = 100,
    },
};

#endif /* TI_NVS_CONF_NVS_EXTERNAL_ENABLE */

/* NVS Region index 0 and 1 refer to NVS and NVS SPI respectively */
const NVS_Config NVS_config[CC1352P_MESHNODE_NVSCOUNT] = {
#if TI_NVS_CONF_NVS_INTERNAL_ENABLE
    {
        .fxnTablePtr = &NVSCC26XX_fxnTable,
        .object = &nvsCC26xxObjects[0],
        .hwAttrs = &nvsCC26xxHWAttrs[0],
    },
#endif
#if TI_NVS_CONF_NVS_EXTERNAL_ENABLE
    {
        .fxnTablePtr = &NVSSPI25X_fxnTable,
        .object = &nvsSPI25XObjects[0],
        .hwAttrs = &nvsSPI25XHWAttrs[0],
    },
#endif
};

const uint_least8_t NVS_count = CC1352P_MESHNODE_NVSCOUNT;

#endif /* TI_NVS_CONF_ENABLE */

/*
 *  =============================== PIN ===============================
 */
#include <ti/drivers/PIN.h>
#include <ti/drivers/pin/PINCC26XX.h>

const PIN_Config BoardGpioInitTable[] = {

    // Use general configuration defines to avoid duplicating configurations when opening pins in application code.

    BOARD_PINCONFIG_PIN_RLED,
    BOARD_PINCONFIG_PIN_GLED,
    BOARD_PINCONFIG_PIN_BTN1,
    BOARD_PINCONFIG_UART0_RX,
    BOARD_PINCONFIG_UART0_TX,
    BOARD_PINCONFIG_UART1_RX,
    BOARD_PINCONFIG_UART1_TX,
    BOARD_PINCONFIG_SPI0_MOSI,
    BOARD_PINCONFIG_SPI0_MISO,
    BOARD_PINCONFIG_SPI0_CLK,
    BOARD_PINCONFIG_SPI0_CSN,
    BOARD_PINCONFIG_DIO_SEL_RF_24GHZ,
    BOARD_PINCONFIG_DIO_SEL_RF_HIGH_PA,
    BOARD_PINCONFIG_DIO_SEL_RF_SUB1GHZ,
    BOARD_PINCONFIG_DIO_USBCONNECTED,
    BOARD_PINCONFIG_DIO_ANTSEL_SUBGHZ,
    BOARD_PINCONFIG_DIO_ANTSEL_EXT,
    BOARD_PINCONFIG_DIO_ANTSEL_24GHZ,
    BOARD_PINCONFIG_DIO_CONNECT_BATT,
    BOARD_PINCONFIG_DIO_CHARGER_EN,
    BOARD_PINCONFIG_DIO_CHARGER_STAT,
    BOARD_PINCONFIG_DIO_BLE_GPIO,
    BOARD_PINCONFIG_DIO_FLASH_RESETn,
    BOARD_PINCONFIG_DIO_FLASH_WPn,

    PIN_TERMINATE};

const PINCC26XX_HWAttrs PINCC26XX_hwAttrs = {
    .intPriority = ~0,
    .swiPriority = 0
};

/*
 *  =============================== Power ===============================
 */
#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerCC26X2.h>
#include "clock-arch.h"

const PowerCC26X2_Config PowerCC26X2_config = {
    .policyInitFxn      = NULL,
    .policyFxn          = &clock_arch_standby_policy,
    .calibrateFxn       = &PowerCC26XX_calibrate,
    .enablePolicy       = true,
    .calibrateRCOSC_LF  = true,
    .calibrateRCOSC_HF  = true,
};

/*
 *  =============================== PWM ===============================
 *  Remove unused entries to reduce flash usage both in Board.c and Board.h
 */
#include <ti/drivers/PWM.h>
#include <ti/drivers/pwm/PWMTimerCC26XX.h>

PWMTimerCC26XX_Object pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWMCOUNT];

const PWMTimerCC26XX_HwAttrs pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWMCOUNT] = {
    { .pwmPin = CC1352P_MESHNODE_PWMPIN0, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER0A },
    { .pwmPin = CC1352P_MESHNODE_PWMPIN1, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER0B },
    { .pwmPin = CC1352P_MESHNODE_PWMPIN2, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER1A },
    { .pwmPin = CC1352P_MESHNODE_PWMPIN3, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER1B },
    { .pwmPin = CC1352P_MESHNODE_PWMPIN4, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER2A },
    { .pwmPin = CC1352P_MESHNODE_PWMPIN5, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER2B },
    { .pwmPin = CC1352P_MESHNODE_PWMPIN6, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER3A },
    { .pwmPin = CC1352P_MESHNODE_PWMPIN7, .gpTimerUnit = CC1352P_MESHNODE_GPTIMER3B },
};

const PWM_Config PWM_config[CC1352P_MESHNODE_PWMCOUNT] = {
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM0], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM0] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM1], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM1] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM2], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM2] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM3], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM3] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM4], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM4] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM5], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM5] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM6], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM6] },
    { &PWMTimerCC26XX_fxnTable, &pwmtimerCC26xxObjects[CC1352P_MESHNODE_PWM7], &pwmtimerCC26xxHWAttrs[CC1352P_MESHNODE_PWM7] },
};

const uint_least8_t PWM_count = CC1352P_MESHNODE_PWMCOUNT;

/*
 *  =============================== RF Driver ===============================
 */
#include <ti/drivers/rf/RF.h>

/*
 *  Board-specific callback function to set the correct antenna path.
 *
 *  This function is called by the RF driver on global driver events.
 *  It contains a default implementation to set the correct antenna path.
 *  This function is defined in the file CC1352P_MESHNODE_fxns.c
 */
extern void rfDriverCallback(RF_Handle client, RF_GlobalEvent events, void* arg);

const RFCC26XX_HWAttrsV2 RFCC26XX_hwAttrs = {
    .hwiPriority        = ~0,     /* Lowest HWI priority */
    .swiPriority        = 0,      /* Lowest SWI priority */
    .xoscHfAlwaysNeeded = true,   /* Keep XOSC dependency while in standby */

    /* Register the board specific callback */
    .globalCallback     = &rfDriverCallback,

    /* Subscribe the callback to both events */
    .globalEventMask    = RF_GlobalEventRadioSetup | RF_GlobalEventRadioPowerDown
};

/*
 *  =============================== SD ===============================
 */
#include <ti/drivers/SD.h>
#include <ti/drivers/sd/SDSPI.h>

#if TI_SD_CONF_ENABLE

#if !(TI_SPI_CONF_SPI0_ENABLE)
#error "SD driver requires SPI0 enabled"
#endif

SDSPI_Object sdspiObjects[CC1352P_MESHNODE_SDCOUNT];

const SDSPI_HWAttrs sdspiHWAttrs[CC1352P_MESHNODE_SDCOUNT] = {
    {
        .spiIndex = CC1352P_MESHNODE_SPI0,
        .spiCsGpioIndex = CC1352P_MESHNODE_SDSPI_CS
    }
};

const SD_Config SD_config[CC1352P_MESHNODE_SDCOUNT] = {
    {
        .fxnTablePtr = &SDSPI_fxnTable,
        .object = &sdspiObjects[CC1352P_MESHNODE_SDSPI0],
        .hwAttrs = &sdspiHWAttrs[CC1352P_MESHNODE_SDSPI0]
    },
};

const uint_least8_t SD_count = CC1352P_MESHNODE_SDCOUNT;

#endif /* TI_SD_CONF_ENABLE */

/*
 *  =============================== SPI DMA ===============================
 */
#include <ti/drivers/SPI.h>
#include <ti/drivers/spi/SPICC26X2DMA.h>

#if TI_SPI_CONF_ENABLE

SPICC26X2DMA_Object spiCC26X2DMAObjects[CC1352P_MESHNODE_SPICOUNT];

/*
 * NOTE: The SPI instances below can be used by the SD driver to communicate
 * with a SD card via SPI.  The 'defaultTxBufValue' fields below are set to 0xFF
 * to satisfy the SDSPI driver requirement.
 */
const SPICC26X2DMA_HWAttrs spiCC26X2DMAHWAttrs[CC1352P_MESHNODE_SPICOUNT] = {
#if TI_SPI_CONF_SPI0_ENABLE
    {
        .baseAddr           = SSI0_BASE,
        .intNum             = INT_SSI0_COMB,
        .intPriority        = ~0,
        .swiPriority        = 0,
        .powerMngrId        = PowerCC26XX_PERIPH_SSI0,
        .defaultTxBufValue  = 0xFF,
        .rxChannelBitMask   = 1<<UDMA_CHAN_SSI0_RX,
        .txChannelBitMask   = 1<<UDMA_CHAN_SSI0_TX,
        .mosiPin            = CC1352P_MESHNODE_SPI0_MOSI,
        .misoPin            = CC1352P_MESHNODE_SPI0_MISO,
        .clkPin             = CC1352P_MESHNODE_SPI0_CLK,
        .csnPin             = CC1352P_MESHNODE_SPI0_CSN,
        .minDmaTransferSize = 10
    },
#endif
#if TI_SPI_CONF_SPI1_ENABLE
    {
        .baseAddr           = SSI1_BASE,
        .intNum             = INT_SSI1_COMB,
        .intPriority        = ~0,
        .swiPriority        = 0,
        .powerMngrId        = PowerCC26XX_PERIPH_SSI1,
        .defaultTxBufValue  = 0xFF,
        .rxChannelBitMask   = 1<<UDMA_CHAN_SSI1_RX,
        .txChannelBitMask   = 1<<UDMA_CHAN_SSI1_TX,
        .mosiPin            = CC1352P_MESHNODE_SPI1_MOSI,
        .misoPin            = CC1352P_MESHNODE_SPI1_MISO,
        .clkPin             = CC1352P_MESHNODE_SPI1_CLK,
        .csnPin             = CC1352P_MESHNODE_SPI1_CSN,
        .minDmaTransferSize = 10
    },
#endif
};

const SPI_Config SPI_config[CC1352P_MESHNODE_SPICOUNT] = {
#if TI_SPI_CONF_SPI0_ENABLE
    {
         .fxnTablePtr = &SPICC26X2DMA_fxnTable,
         .object      = &spiCC26X2DMAObjects[CC1352P_MESHNODE_SPI0],
         .hwAttrs     = &spiCC26X2DMAHWAttrs[CC1352P_MESHNODE_SPI0]
    },
#endif
#if TI_SPI_CONF_SPI1_ENABLE
    {
         .fxnTablePtr = &SPICC26X2DMA_fxnTable,
         .object      = &spiCC26X2DMAObjects[CC1352P_MESHNODE_SPI1],
         .hwAttrs     = &spiCC26X2DMAHWAttrs[CC1352P_MESHNODE_SPI1]
    },
#endif
};

const uint_least8_t SPI_count = CC1352P_MESHNODE_SPICOUNT;

#endif /* TI_SPI_CONF_ENABLE */

/*
 *  =============================== UART ===============================
 */
#include <ti/drivers/UART.h>
#include <ti/drivers/uart/UARTCC26XX.h>

#if TI_UART_CONF_ENABLE

UARTCC26XX_Object uartCC26XXObjects[CC1352P_MESHNODE_UARTCOUNT];

uint8_t uartCC26XXRingBuffer[CC1352P_MESHNODE_UARTCOUNT][32];

const UARTCC26XX_HWAttrsV2 uartCC26XXHWAttrs[CC1352P_MESHNODE_UARTCOUNT] = {
#if TI_UART_CONF_UART0_ENABLE
    {
        .baseAddr       = UART0_BASE,
        .powerMngrId    = PowerCC26XX_PERIPH_UART0,
        .intNum         = INT_UART0_COMB,
        .intPriority    = ~0,
        .swiPriority    = 0,
        .txPin          = CC1352P_MESHNODE_UART0_TX,
        .rxPin          = CC1352P_MESHNODE_UART0_RX,
        .ctsPin         = PIN_UNASSIGNED,
        .rtsPin         = PIN_UNASSIGNED,
        .ringBufPtr     = uartCC26XXRingBuffer[CC1352P_MESHNODE_UART0],
        .ringBufSize    = sizeof(uartCC26XXRingBuffer[CC1352P_MESHNODE_UART0]),
        .txIntFifoThr   = UARTCC26XX_FIFO_THRESHOLD_1_8,
        .rxIntFifoThr   = UARTCC26XX_FIFO_THRESHOLD_4_8,
        .errorFxn       = NULL
    },
#endif
#if TI_UART_CONF_UART1_ENABLE
    {
        .baseAddr       = UART1_BASE,
        .powerMngrId    = PowerCC26X2_PERIPH_UART1,
        .intNum         = INT_UART1_COMB,
        .intPriority    = ~0,
        .swiPriority    = 0,
        .txPin          = CC1352P_MESHNODE_UART1_TX,
        .rxPin          = CC1352P_MESHNODE_UART1_RX,
        .ctsPin         = PIN_UNASSIGNED,
        .rtsPin         = PIN_UNASSIGNED,
        .ringBufPtr     = uartCC26XXRingBuffer[CC1352P_MESHNODE_UART1],
        .ringBufSize    = sizeof(uartCC26XXRingBuffer[CC1352P_MESHNODE_UART1]),
        .txIntFifoThr   = UARTCC26XX_FIFO_THRESHOLD_1_8,
        .rxIntFifoThr   = UARTCC26XX_FIFO_THRESHOLD_4_8,
        .errorFxn = NULL
    },
#endif
};

const UART_Config UART_config[CC1352P_MESHNODE_UARTCOUNT] = {
#if TI_UART_CONF_UART0_ENABLE
    {
        .fxnTablePtr = &UARTCC26XX_fxnTable,
        .object      = &uartCC26XXObjects[CC1352P_MESHNODE_UART0],
        .hwAttrs     = &uartCC26XXHWAttrs[CC1352P_MESHNODE_UART0]
    },
#endif
#if TI_UART_CONF_UART1_ENABLE
    {
        .fxnTablePtr = &UARTCC26XX_fxnTable,
        .object      = &uartCC26XXObjects[CC1352P_MESHNODE_UART1],
        .hwAttrs     = &uartCC26XXHWAttrs[CC1352P_MESHNODE_UART1]
    },
#endif
};

const uint_least8_t UART_count = CC1352P_MESHNODE_UARTCOUNT;

#endif /* TI_UART_CONF_ENABLE */

/*
 *  =============================== UDMA ===============================
 */
#include <ti/drivers/dma/UDMACC26XX.h>

UDMACC26XX_Object udmaObjects[CC1352P_MESHNODE_UDMACOUNT];

const UDMACC26XX_HWAttrs udmaHWAttrs[CC1352P_MESHNODE_UDMACOUNT] = {
    {
        .baseAddr    = UDMA0_BASE,
        .powerMngrId = PowerCC26XX_PERIPH_UDMA,
        .intNum      = INT_DMA_ERR,
        .intPriority = ~0
    }
};

const UDMACC26XX_Config UDMACC26XX_config[CC1352P_MESHNODE_UDMACOUNT] = {
    {
         .object  = &udmaObjects[CC1352P_MESHNODE_UDMA0],
         .hwAttrs = &udmaHWAttrs[CC1352P_MESHNODE_UDMA0]
    },
};



/*
 *  =============================== Watchdog ===============================
 */
#include <ti/drivers/Watchdog.h>
#include <ti/drivers/watchdog/WatchdogCC26XX.h>

WatchdogCC26XX_Object watchdogCC26XXObjects[CC1352P_MESHNODE_WATCHDOGCOUNT];

const WatchdogCC26XX_HWAttrs watchdogCC26XXHWAttrs[CC1352P_MESHNODE_WATCHDOGCOUNT] = {
    {
        .baseAddr    = WDT_BASE,
        .reloadValue = 1000 /* Reload value in milliseconds */
    },
};

const Watchdog_Config Watchdog_config[CC1352P_MESHNODE_WATCHDOGCOUNT] = {
    {
        .fxnTablePtr = &WatchdogCC26XX_fxnTable,
        .object      = &watchdogCC26XXObjects[CC1352P_MESHNODE_WATCHDOG0],
        .hwAttrs     = &watchdogCC26XXHWAttrs[CC1352P_MESHNODE_WATCHDOG0]
    },
};

const uint_least8_t Watchdog_count = CC1352P_MESHNODE_WATCHDOGCOUNT;

/*
 *  Board-specific initialization function to disable external flash.
 *  This function is defined in the file CC1352P_MESHNODE_fxns.c
 */
extern void Board_initHook(void);

/*
 *  ======== CC1352P_MESHNODE_initGeneral ========
 */
void CC1352P_MESHNODE_initGeneral(void)
{
    Power_init();

    if (PIN_init(BoardGpioInitTable) != PIN_SUCCESS) {
        /* Error with PIN_init */
        while (1);
    }

    /* Perform board-specific initialization */
    Board_initHook();
}

/*
 *  ======== Board_init ========
 */
void Board_init(void)
{
    CC1352P_MESHNODE_initGeneral();
}
