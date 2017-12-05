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

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

void Led_Init()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();

  GPIO_InitTypeDef led1_d10_A8;
  led1_d10_A8.Pin = GPIO_PIN_8;
  led1_d10_A8.Mode = GPIO_MODE_OUTPUT_PP;
  led1_d10_A8.Pull = GPIO_PULLDOWN;
  led1_d10_A8.Speed = GPIO_SPEED_HIGH;

  HAL_GPIO_Init(GPIOA, &led1_d10_A8);
}

void Button_Init()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();

	GPIO_InitTypeDef p_button;

	p_button.Pin = GPIO_PIN_11;
	p_button.Mode = GPIO_MODE_IT_RISING;
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
	HAL_InitTick(14);
	GPIOA->ODR |= GPIO_PIN_8;
	HAL_Delay(1000);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
