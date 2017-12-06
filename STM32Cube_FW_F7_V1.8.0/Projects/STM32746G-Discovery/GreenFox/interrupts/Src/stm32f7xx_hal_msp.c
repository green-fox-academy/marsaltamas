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

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
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

void Led_Init()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitTypeDef led1_d10_A8;
  led1_d10_A8.Pin = GPIO_PIN_8;
  led1_d10_A8.Mode = GPIO_MODE_OUTPUT_PP;
  led1_d10_A8.Pull = GPIO_PULLDOWN;
  led1_d10_A8.Speed = GPIO_SPEED_HIGH;
  //led1_d10_A8.Alternate = GPIO_AF1_TIM2;

  HAL_GPIO_Init(GPIOA, &led1_d10_A8);
}

void Led_InitA0()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitTypeDef led1_d10_A8;
  led1_d10_A8.Pin = GPIO_PIN_0;
  led1_d10_A8.Mode = GPIO_MODE_OUTPUT_PP;
  led1_d10_A8.Pull = GPIO_PULLDOWN;
  led1_d10_A8.Speed = GPIO_SPEED_HIGH;
  //led1_d10_A8.Alternate = GPIO_AF1_TIM2;

  HAL_GPIO_Init(GPIOA, &led1_d10_A8);
}


void Button_Init()
{
  __HAL_RCC_GPIOI_CLK_ENABLE();

 GPIO_InitTypeDef p_button;

 p_button.Pin = GPIO_PIN_11;
 p_button.Mode = GPIO_MODE_OUTPUT_PP;
 p_button.Pull = GPIO_NOPULL;
 p_button.Speed = GPIO_SPEED_FAST;

 HAL_GPIO_Init(GPIOI, &p_button);
}

void EXTI15_10_IRQHandler()
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t Gpio_pin)
{
  HAL_InitTick(14); // https://electronics.stackexchange.com/questions/212194/stm32f7-gets-stuck-in-external-interrupt-callback-function
  GPIOA->ODR |= GPIO_PIN_8;
  HAL_Delay(1000);
}

// tests PWM
void TIM1_PWM_Init()
{
  __HAL_RCC_TIM1_CLK_ENABLE();

  TIM_HandleTypeDef    TimHandle;
  TimHandle.Instance = TIM1;

  TimHandle.Init.Prescaler         = 54000;
  TimHandle.Init.Period            = 1000;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;
  //TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

  //HAL_TIM_PWM_Init(&TimHandle);
  HAL_TIM_Base_Init(&TimHandle);

  TIM_OC_InitTypeDef sConfig;

//  sConfig.OCMode       = TIM_OCMODE_PWM1;
//  sConfig.OCPolarity   = TIM_OCPOLARITY_HIGH;
//  sConfig.OCFastMode   = TIM_OCFAST_DISABLE;
//  sConfig.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
//  sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
//  sConfig.OCIdleState  = TIM_OCIDLESTATE_RESET;

  /* Set the pulse value for channel 1 */
//  sConfig.Pulse = 100;
//  HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);


  HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
}

// used for testing timer interrupt
void TIM2_IT_Init(TIM_HandleTypeDef *Tim2Handle)
{
  __HAL_RCC_TIM2_CLK_ENABLE();

  Tim2Handle->Instance = TIM2;

  Tim2Handle->Init.Prescaler         = 0xFFFF;
  Tim2Handle->Init.Period            = 1647 - 1;
  Tim2Handle->Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
  Tim2Handle->Init.CounterMode       = TIM_COUNTERMODE_UP;
//  Tim2Handle->Init.RepetitionCounter = 0;
//  Tim2Handle->Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

//  HAL_TIM_PWM_Init(&TimHandle);

//  HAL_TIM_PWM_ConfigChannel(Tim2Handle, &sConfig, TIM_CHANNEL_1);
//  HAL_TIM_IRQHandler(Tim2Handle);

  /*##-1- Enable peripheral clock #################################*/
  /* TIMx Peripheral clock enable */
//  TIMx_CLK_ENABLE();

  /*##-2- Configure the NVIC for TIMx ########################################*/
  /* Set the TIMx priority */

  HAL_TIM_Base_Init(Tim2Handle);
  HAL_TIM_Base_Start_IT(Tim2Handle);

  HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);

  /* Enable the TIMx global Interrupt */
  HAL_NVIC_EnableIRQ(TIM2_IRQn);

  printf("tim2 init called\n");
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
