/**
  ******************************************************************************
  * @file    stm32f7xx_hal_msp.c
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   HAL MSP module.
  *          This file template is located in the HAL folder and should be copied 
  *          to the user folder.
  *         
  @verbatim
 ===============================================================================
                     ##### How to use this driver #####
 ===============================================================================
    [..]


  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/** @addtogroup STM32F7xx_HAL_Driver
  * @{
  */

/** @defgroup HAL_MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private variables ---------------------------------------------------------*/

extern TIM_HandleTypeDef tim2_handle;

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */
/**
  * @brief  Initializes the Global MSP.
  * @param  None
  * @retval None
  */
void HAL_MspInit(void)
{
}

/**
  * @brief  DeInitializes the Global MSP.
  * @param  None  
  * @retval None
  */
void HAL_MspDeInit(void)
{
  /* NOTE : This function is generated automatically by STM32CubeMX and eventually  
            modified by the user
   */
}

void clock_enabler()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
}

void leda0_a0_init()
{
	GPIO_InitTypeDef leda0_a0;

	leda0_a0.Pin = GPIO_PIN_0;
	leda0_a0.Mode = GPIO_MODE_OUTPUT_PP;
	leda0_a0.Speed = GPIO_SPEED_HIGH;
	leda0_a0.Pull = GPIO_PULLDOWN;

	HAL_GPIO_Init(GPIOA, &leda0_a0);
}

void leda15_d9_init()
{
	GPIO_InitTypeDef leda15_d9;

	leda15_d9.Pin = GPIO_PIN_15;
	leda15_d9.Mode = GPIO_MODE_AF_PP;
	leda15_d9.Speed = GPIO_SPEED_HIGH;
	leda15_d9.Pull = GPIO_PULLDOWN;
	leda15_d9.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &leda15_d9);
}

void buttona5_f6_init()
{
	GPIO_InitTypeDef buttona5_f6;

	buttona5_f6.Pin = GPIO_PIN_6;
	buttona5_f6.Mode = GPIO_MODE_IT_RISING;
	buttona5_f6.Speed = GPIO_SPEED_HIGH;
	buttona5_f6.Pull = GPIO_PULLUP;

	HAL_GPIO_Init(GPIOF, &buttona5_f6);

	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void tim2_init()
{
	// enable in clock_enabler()

	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Period = 1000;
	tim2_handle.Init.Prescaler = 0;
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&tim2_handle);
	HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_1);

	TIM_OC_InitTypeDef oc_tim2;

	oc_tim2.OCMode = TIM_OCMODE_PWM1;
	oc_tim2.Pulse = 900;

	HAL_TIM_PWM_ConfigChannel(&tim2_handle, &oc_tim2, TIM_CHANNEL_1);
}



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
