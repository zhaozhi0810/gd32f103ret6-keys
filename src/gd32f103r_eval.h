/*!
    \file    gd32f103r_eval.h
    \brief   definitions for GD32F103C_EVAL's leds, keys and COM ports hardware resources

    \version 2014-12-26, V1.0.0, demo for GD32F10x
    \version 2017-06-20, V2.0.0, demo for GD32F10x
    \version 2018-07-31, V2.1.0, demo for GD32F10x
*/

/*
    Copyright (c) 2018, GigaDevice Semiconductor Inc.

    All rights reserved.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#ifndef GD32F103C_EVAL_H
#define GD32F103C_EVAL_H

#ifdef cplusplus
 extern "C" {
#endif

#include "gd32f10x.h"
     


typedef enum 
{
    KEY_USER1 = 0,
    KEY_USER2 = 1,
    KEY_USER3 = 2,
	KEY_USER4,
	KEY_USER5,
	KEY_USER6,
	KEY_USER7,
	KEY_USER8,
	KEY_USER9,
	KEY_USER10,
	KEY_USER11,
	KEY_USER12,
	KEY_USER13,
	KEY_USER14,
	KEY_USER15,
	KEY_MAX
} key_typedef_enum;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} keymode_typedef_enum;



#define COMn                             2U

#define EVAL_COM0                        USART0
#define EVAL_COM0_CLK                    RCU_USART0
#define EVAL_COM0_TX_PIN                 GPIO_PIN_9
#define EVAL_COM0_RX_PIN                 GPIO_PIN_10
#define EVAL_COM0_GPIO_PORT              GPIOA
#define EVAL_COM0_GPIO_CLK               RCU_GPIOA

#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCU_USART1
#define EVAL_COM1_TX_PIN                 GPIO_PIN_2
#define EVAL_COM1_RX_PIN                 GPIO_PIN_3
#define EVAL_COM1_GPIO_PORT              GPIOA
#define EVAL_COM1_GPIO_CLK               RCU_GPIOA

#define KEYn                             KEY_MAX

/* wakeup push-button */
#define KEY_USER1_PIN                   GPIO_PIN_8
#define KEY_USER1_GPIO_PORT             GPIOB
#define KEY_USER1_GPIO_CLK              RCU_GPIOB
#define KEY_USER1_EXTI_LINE             EXTI_8
#define KEY_USER1_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOB
#define KEY_USER1_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_0
#define KEY_USER1_EXTI_IRQn             EXTI5_9_IRQn  

/* tamper push-button */
#define KEY_USER2_PIN                   GPIO_PIN_9
#define KEY_USER2_GPIO_PORT             GPIOB
#define KEY_USER2_GPIO_CLK              RCU_GPIOB
#define KEY_USER2_EXTI_LINE             EXTI_9
#define KEY_USER2_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOB
#define KEY_USER2_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_9
#define KEY_USER2_EXTI_IRQn             EXTI5_9_IRQn

/* user push-button */
#define KEY_USER3_PIN                     GPIO_PIN_10
#define KEY_USER3_GPIO_PORT               GPIOB
#define KEY_USER3_GPIO_CLK                RCU_GPIOB
#define KEY_USER3_EXTI_LINE               EXTI_10
#define KEY_USER3_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOB
#define KEY_USER3_EXTI_PIN_SOURCE         GPIO_PIN_SOURCE_10
#define KEY_USER3_EXTI_IRQn               EXTI10_15_IRQn


/* wakeup push-button */
#define KEY_USER4_PIN                   GPIO_PIN_11
#define KEY_USER4_GPIO_PORT             GPIOB
#define KEY_USER4_GPIO_CLK              RCU_GPIOB
#define KEY_USER4_EXTI_LINE             EXTI_11
#define KEY_USER4_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOB
#define KEY_USER4_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_11
#define KEY_USER4_EXTI_IRQn             EXTI10_15_IRQn  

/* tamper push-button */
#define KEY_USER5_PIN                   GPIO_PIN_12
#define KEY_USER5_GPIO_PORT             GPIOB
#define KEY_USER5_GPIO_CLK              RCU_GPIOB
#define KEY_USER5_EXTI_LINE             EXTI_12
#define KEY_USER5_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOB
#define KEY_USER5_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_12
#define KEY_USER5_EXTI_IRQn             EXTI10_15_IRQn

/* user push-button */
#define KEY_USER6_PIN                     GPIO_PIN_13
#define KEY_USER6_GPIO_PORT               GPIOB
#define KEY_USER6_GPIO_CLK                RCU_GPIOB
#define KEY_USER6_EXTI_LINE               EXTI_13
#define KEY_USER6_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOB
#define KEY_USER6_EXTI_PIN_SOURCE         GPIO_PIN_SOURCE_13
#define KEY_USER6_EXTI_IRQn               EXTI10_15_IRQn



/* wakeup push-button */
#define KEY_USER7_PIN                   GPIO_PIN_14
#define KEY_USER7_GPIO_PORT             GPIOB
#define KEY_USER7_GPIO_CLK              RCU_GPIOB
#define KEY_USER7_EXTI_LINE             EXTI_14
#define KEY_USER7_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOB
#define KEY_USER7_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_14
#define KEY_USER7_EXTI_IRQn             EXTI10_15_IRQn  

/* tamper push-button */
#define KEY_USER8_PIN                   GPIO_PIN_15
#define KEY_USER8_GPIO_PORT             GPIOB
#define KEY_USER8_GPIO_CLK              RCU_GPIOB
#define KEY_USER8_EXTI_LINE             EXTI_15
#define KEY_USER8_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOB
#define KEY_USER8_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_15
#define KEY_USER8_EXTI_IRQn             EXTI10_15_IRQn

/* user push-button */
#define KEY_USER9_PIN                     GPIO_PIN_0
#define KEY_USER9_GPIO_PORT               GPIOC
#define KEY_USER9_GPIO_CLK                RCU_GPIOC
#define KEY_USER9_EXTI_LINE               EXTI_0
#define KEY_USER9_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOC
#define KEY_USER9_EXTI_PIN_SOURCE         GPIO_PIN_SOURCE_0
#define KEY_USER9_EXTI_IRQn               EXTI0_IRQn


/* wakeup push-button */
#define KEY_USER10_PIN                   GPIO_PIN_1
#define KEY_USER10_GPIO_PORT             GPIOC
#define KEY_USER10_GPIO_CLK              RCU_GPIOC
#define KEY_USER10_EXTI_LINE             EXTI_1
#define KEY_USER10_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOC
#define KEY_USER10_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_1
#define KEY_USER10_EXTI_IRQn             EXTI1_IRQn  

/* tamper push-button */
#define KEY_USER11_PIN                   GPIO_PIN_2
#define KEY_USER11_GPIO_PORT             GPIOC
#define KEY_USER11_GPIO_CLK              RCU_GPIOC
#define KEY_USER11_EXTI_LINE             EXTI_2
#define KEY_USER11_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOC
#define KEY_USER11_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_2
#define KEY_USER11_EXTI_IRQn             EXTI2_IRQn

/* user push-button */
#define KEY_USER12_PIN                     GPIO_PIN_3
#define KEY_USER12_GPIO_PORT               GPIOC
#define KEY_USER12_GPIO_CLK                RCU_GPIOC
#define KEY_USER12_EXTI_LINE               EXTI_3
#define KEY_USER12_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOC
#define KEY_USER12_EXTI_PIN_SOURCE         GPIO_PIN_SOURCE_3
#define KEY_USER12_EXTI_IRQn               EXTI3_IRQn


/* wakeup push-button */
#define KEY_USER13_PIN                   GPIO_PIN_4
#define KEY_USER13_GPIO_PORT             GPIOC
#define KEY_USER13_GPIO_CLK              RCU_GPIOC
#define KEY_USER13_EXTI_LINE             EXTI_4
#define KEY_USER13_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOC
#define KEY_USER13_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_4
#define KEY_USER13_EXTI_IRQn             EXTI4_IRQn  

/* tamper push-button */
#define KEY_USER14_PIN                   GPIO_PIN_5
#define KEY_USER14_GPIO_PORT             GPIOC
#define KEY_USER14_GPIO_CLK              RCU_GPIOC
#define KEY_USER14_EXTI_LINE             EXTI_5
#define KEY_USER14_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOC
#define KEY_USER14_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_5
#define KEY_USER14_EXTI_IRQn             EXTI5_9_IRQn

/* user push-button */
#define KEY_USER15_PIN                     GPIO_PIN_6
#define KEY_USER15_GPIO_PORT               GPIOC
#define KEY_USER15_GPIO_CLK                RCU_GPIOC
#define KEY_USER15_EXTI_LINE               EXTI_6
#define KEY_USER15_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOC
#define KEY_USER15_EXTI_PIN_SOURCE         GPIO_PIN_SOURCE_6
#define KEY_USER15_EXTI_IRQn               EXTI5_9_IRQn


/* function declarations */
/* configure led GPIO */
//void gd_eval_led_init(led_typedef_enum lednum);
///* turn on selected led */
//void gd_eval_led_on(led_typedef_enum lednum);
///* turn off selected led */
//void gd_eval_led_off(led_typedef_enum lednum);
///* toggle the selected led */
//void gd_eval_led_toggle(led_typedef_enum lednum);
/* configure key */
void gd_eval_key_init(key_typedef_enum key_num, keymode_typedef_enum key_mode);
/* return the selected key state */
uint8_t gd_eval_key_state_get(key_typedef_enum key);
/* configure COM port */
void gd_eval_com_init(uint32_t com);
//配置所有的按键
void gd_all_keys_init(keymode_typedef_enum key_mode);
#ifdef cplusplus
}
#endif

#endif /* GD32F103C_EVAL_H */
