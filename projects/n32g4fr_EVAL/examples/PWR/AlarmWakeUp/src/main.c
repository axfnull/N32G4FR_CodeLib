/*****************************************************************************
 * Copyright (c) 2019, Nations Technologies Inc.
 *
 * All rights reserved.
 * ****************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Nations' name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY NATIONS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL NATIONS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ****************************************************************************/

/**
 * @file main.c
 * @author Nations 
 * @version v1.0.2
 *
 * @copyright Copyright (c) 2019, Nations Technologies Inc. All rights reserved.
 */
#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include "log.h"
#include "n32g4fr_rtc.h"
#include "n32g4fr_pwr.h"
#include "User_LED_Config.h"
#include "User_RTC_Config.h"

/** @addtogroup AlarmWakeup
 * @{
 */


/**
 * @brief  Delay function.
 */
void delay(vu32 nCount)
{
    vu32 index = 0;
    for (index = (34000 * nCount); index != 0; index--)
    {
    }
}


/**
 * @brief  Reconfig the system clock.
 */
void SYSCLKConfig_STOP(uint32_t RCC_PLLMULL)
{
    __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
    /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration */
    /* Enable HSE */
    RCC->CTRL |= ((uint32_t)RCC_CTRL_HSEEN);
    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
       HSEStatus = RCC->CTRL & RCC_CTRL_HSERDF;
       StartUpCounter++;
    } while ((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
    if ((RCC->CTRL & RCC_CTRL_HSERDF) != RESET)
    {
       HSEStatus = (uint32_t)0x01;
    }
    else
    {
       HSEStatus = (uint32_t)0x00;
    }
    if (HSEStatus == (uint32_t)0x01)
    {
       /* Enable Prefetch Buffer */
       FLASH->AC |= FLASH_AC_PRFTBFEN;
       /* Flash 2 wait state */
       FLASH->AC &= (uint32_t)((uint32_t)~FLASH_AC_LATENCY);
       FLASH->AC |= (uint32_t)FLASH_AC_LATENCY_4;
       /* HCLK = SYSCLK */
       RCC->CFG |= (uint32_t)RCC_CFG_AHBPRES_DIV1;
       /* PCLK2 = HCLK */
       RCC->CFG |= (uint32_t)RCC_CFG_APB2PRES_DIV2; // RCC_CFG_APB2PRES_DIV1
       /* PCLK1 = HCLK */
       RCC->CFG |= (uint32_t)RCC_CFG_APB1PRES_DIV4; // RCC_CFG_APB1PRES_DIV2
       /*  PLL configuration: PLLCLK = HSE * 18 = 144 MHz */
       RCC->CFG &= (uint32_t)((uint32_t) ~(RCC_CFG_PLLSRC | RCC_CFG_PLLHSEPRES | RCC_CFG_PLLMULFCT));
       RCC->CFG |= (uint32_t)(RCC_CFG_PLLSRC_HSE | RCC_PLLMULL);
       /* Enable PLL */
       RCC->CTRL |= RCC_CTRL_PLLEN;
       /* Wait till PLL is ready */
       while ((RCC->CTRL & RCC_CTRL_PLLRDF) == 0)
       {
       }
       /* Select PLL as system clock source */
       RCC->CFG &= (uint32_t)((uint32_t) ~(RCC_CFG_SCLKSW));
       RCC->CFG |= (uint32_t)RCC_CFG_SCLKSW_PLL;
       /* Wait till PLL is used as system clock source */
       while ((RCC->CFG & (uint32_t)RCC_CFG_SCLKSTS) != (uint32_t)0x08)
       {
       }
    }
    else
    { 
       /* If HSE fails to start-up, the application will have wrong clock
          configuration. User can add here some code to deal with this error */
    }
}

/**
 * @brief  Main program.
 */
int main(void)
{
    /*!< At this stage the microcontroller clock setting is already configured,
         this is done through SystemInit() function which is called from startup
         file (startup_n32g4fr_xx.s) before to branch to application main.
         To reconfigure the default setting of SystemInit() function, refer to
         system_n32g4fr.c file
       */

    /* Initialize LEDs and USART on n32g4fr-EVAL board */
    LEDInit(LED1_PORT, LED1_PIN);
    LEDOff(LED1_PORT,LED1_PIN);
    log_init();
    log_info("\r\n Alarm Wakeup Config \r\n ");
    /* RTC time and Date default Value */
    RTC_DateAndTimeDefaultVale();
    /* RTC Clock Select, 1: HSE  2:LSE 3: LSI */
    RTC_CLKSourceConfig(3, 0, 1);
    RTC_PrescalerConfig();
    /* RTC Date time and Alarm value set */
    RTC_DateRegulate();
    RTC_TimeRegulate();
    RTC_AlarmRegulate(RTC_A_ALARM);
    /* Enable RTC Alarm Interrupt */
    EXTI17_RTCAlarm_Configuration(ENABLE);
    /* Enable PWR clock */
    RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_PWR, ENABLE);
    while (1)
    {
        /* Turn on LED and prin some flag imformation */
        LEDBlink(LED1_PORT,LED1_PIN);
        delay(400);
        log_info("\r\n start low power! \r\n");
        /* Request to enter STOP mode with regulator in low power mode*/
        PWR_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
        /* Exit the low power ,need to reconfig the system clock */
        SYSCLKConfig_STOP(RCC_CFG_PLLMULFCT18);
        log_init();
        log_info("\r\n Exit low power! \r\n");
        delay(400);
    }
}

