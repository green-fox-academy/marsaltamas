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
#include "main.h"

/** @addtogroup STM32F7xx_HAL_Driver
  * @{
  */

/** @defgroup HAL_MSP
  * @brief HAL MSP module.
  * @{
  */

/* Private variables ---------------------------------------------------------*/

extern TIM_HandleTypeDef tim1_handler;
extern TIM_HandleTypeDef tim2_handler;
extern TIM_HandleTypeDef tim5_handler;
extern UART_HandleTypeDef uart_handle;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

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



void leda0_init()
{
	GPIO_InitTypeDef led_a0_a0;

	led_a0_a0.Pin = GPIO_PIN_0;
	led_a0_a0.Speed = GPIO_SPEED_FAST;
	led_a0_a0.Mode = GPIO_MODE_OUTPUT_PP;
	led_a0_a0.Pull = GPIO_PULLDOWN;

	HAL_GPIO_Init(GPIOA, &led_a0_a0);
}

void ledd9_init()
{
	GPIO_InitTypeDef led_d9_a15;

	led_d9_a15.Pin = GPIO_PIN_15;
	led_d9_a15.Speed = GPIO_SPEED_FAST;
	led_d9_a15.Mode = GPIO_MODE_AF_PP;
	led_d9_a15.Pull = GPIO_NOPULL;
	led_d9_a15.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOA, &led_d9_a15);
}

void ledd3_init()
{
	GPIO_InitTypeDef led_d3_b4;

	led_d3_b4.Pin = GPIO_PIN_4;
	led_d3_b4.Speed = GPIO_SPEED_FAST;
	led_d3_b4.Mode = GPIO_MODE_OUTPUT_PP;
	led_d3_b4.Pull = GPIO_PULLDOWN;
	//led_d3_b4.Alternate = GPIO_AF1_TIM2;

	HAL_GPIO_Init(GPIOB, &led_d3_b4);
}

void enable_clocks()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_TIM1_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
	__HAL_RCC_TIM5_CLK_ENABLE();
}

// TIM1 used to flash led in 500 ms feq
void tim1_hanlder_init()
{
	// enable clock tim1 in enable_clock()

	tim1_handler.Instance = TIM1;
	tim1_handler.Init.Prescaler = 54000;
	tim1_handler.Init.Period = 4000 - 1;
	tim1_handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim1_handler.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim1_handler);
	HAL_TIM_Base_Start(&tim1_handler);
}

void tim2_handler_init()
{
	// enable clock tim2 in enable_clock()

	tim2_handler.Instance = TIM2;
	tim2_handler.Init.Prescaler = 0;
	tim2_handler.Init.Period = 5000;
	tim2_handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handler.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_PWM_Init(&tim2_handler);

	TIM_OC_InitTypeDef oc_conf_tim2;

	oc_conf_tim2.OCMode = TIM_OCMODE_PWM1;
	oc_conf_tim2.Pulse = 2500;

	HAL_TIM_PWM_ConfigChannel(&tim2_handler, &oc_conf_tim2, TIM_CHANNEL_1);

	HAL_TIM_PWM_Start(&tim2_handler, TIM_CHANNEL_1);
}

void tim5_handler_init()
{
	// enable clock tim5 in enable_clock()

	tim5_handler.Instance = TIM5;
	tim5_handler.Init.Period = 2000 - 1;
	tim5_handler.Init.Prescaler = 54000 - 1;
	tim5_handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim5_handler.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim5_handler);
	HAL_TIM_Base_Start_IT(&tim5_handler);

}

void uart_handle_init()
{
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void interrupt_enable_tim5()
{
	HAL_NVIC_SetPriority(TIM5_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(TIM5_IRQn);
}

void interrupt_enable_pb_i11()
{
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
