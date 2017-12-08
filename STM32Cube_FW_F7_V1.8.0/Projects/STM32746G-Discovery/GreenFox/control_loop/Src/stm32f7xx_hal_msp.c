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

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

extern TIM_HandleTypeDef tim2_handle;
extern TIM_HandleTypeDef tim3_handle;
extern TIM_IC_InitTypeDef tim3_ic_config;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


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
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();

	__HAL_RCC_TIM2_CLK_ENABLE();
	__HAL_RCC_TIM3_CLK_ENABLE();
}

void button_up_init()
{
	GPIO_InitTypeDef button_up_a0_pa0;

	button_up_a0_pa0.Pin = GPIO_PIN_0;
	button_up_a0_pa0.Speed = GPIO_SPEED_HIGH;
	button_up_a0_pa0.Mode = GPIO_MODE_IT_FALLING;
	button_up_a0_pa0.Pull = GPIO_PULLUP;

	HAL_GPIO_Init(GPIOA, &button_up_a0_pa0);

	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 14, 0);
}

void button_down_init()
{
	GPIO_InitTypeDef button_up_a1_pf10;

	button_up_a1_pf10.Pin = GPIO_PIN_10;
	button_up_a1_pf10.Speed = GPIO_SPEED_HIGH;
	button_up_a1_pf10.Mode = GPIO_MODE_IT_FALLING;
	button_up_a1_pf10.Pull = GPIO_PULLUP;

	HAL_GPIO_Init(GPIOF, &button_up_a1_pf10);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 14, 0);
}

void pwm_pin_d9_pa15_init()
{
	GPIO_InitTypeDef pwm_pin_d9_pa15;

	pwm_pin_d9_pa15.Pin = GPIO_PIN_15;
	pwm_pin_d9_pa15.Speed = GPIO_SPEED_FAST;
	pwm_pin_d9_pa15.Mode = GPIO_MODE_AF_PP;
	pwm_pin_d9_pa15.Pull = GPIO_NOPULL;
	pwm_pin_d9_pa15.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &pwm_pin_d9_pa15);
}

void tim2_init()
{
	// TIM1 clock enabled in clock_enabler()
	tim2_handle.Instance = TIM2;
	tim2_handle.Init.Period = 1000;
	tim2_handle.Init.Prescaler = 10000;
	tim2_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&tim2_handle);


	TIM_OC_InitTypeDef tim2_oc_config;

	tim2_oc_config.OCMode = TIM_OCMODE_PWM1;
	tim2_oc_config.Pulse = 0;

	HAL_TIM_PWM_ConfigChannel(&tim2_handle, &tim2_oc_config, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&tim2_handle, TIM_CHANNEL_1);
}

void speed_ic_pin_d3_pb4_init()
{
	GPIO_InitTypeDef speed_ic_pin_d3_pb4;

	speed_ic_pin_d3_pb4.Pin = GPIO_PIN_4;
	speed_ic_pin_d3_pb4.Speed = GPIO_SPEED_FAST;
	speed_ic_pin_d3_pb4.Mode = GPIO_MODE_AF_OD;
	speed_ic_pin_d3_pb4.Pull = GPIO_PULLUP;
	speed_ic_pin_d3_pb4.Alternate = GPIO_AF2_TIM3;

	HAL_GPIO_Init(GPIOB, &speed_ic_pin_d3_pb4);

//	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
//	HAL_NVIC_SetPriority(EXTI4_IRQn, 15, 0);
}

void tim3_init()
{
	// TIM1 clock enabled in clock_enabler()
	tim3_handle.Instance = TIM3;
	tim3_handle.Init.Period = 0xFFFF;
	tim3_handle.Init.Prescaler = 10800;
	tim3_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim3_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_IC_Init(&tim3_handle);

	//TIM_IC_InitTypeDef tim3_ic_config;

	tim3_ic_config.ICPolarity  = TIM_ICPOLARITY_RISING;
	tim3_ic_config.ICSelection = TIM_ICSELECTION_DIRECTTI;
	tim3_ic_config.ICPrescaler = TIM_ICPSC_DIV2;

	HAL_NVIC_EnableIRQ(TIM3_IRQn);
	HAL_NVIC_SetPriority(TIM3_IRQn, 15, 0);

	HAL_TIM_IC_ConfigChannel(&tim3_handle, &tim3_ic_config, TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&tim3_handle, TIM_CHANNEL_1);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
