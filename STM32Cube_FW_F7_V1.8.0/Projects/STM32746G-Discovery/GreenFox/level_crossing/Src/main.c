 /**
  ******************************************************************************
  * @file    Templates/Src/main.c 
  * @author  MCD Application Team
  * @version V1.0.3
  * @date    22-April-2016 
  * @brief   STM32F7xx HAL API Template project 
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
#include "main.h"
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define OPEN 0
#define SECURING 1
#define SECURED 2
#define OPENING 3
#define TRUE 1
#define FALSE 0

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef tim1_handler;
volatile int state = 0;
volatile int previous_state = -1;
volatile int state_change_enabled = TRUE;

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

/* Private functions ---------------------------------------------------------*/

void enable_clocks()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_TIM1_CLK_ENABLE();
}

void init_uart()
{
	uart_handle.Init.BaudRate   = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits   = UART_STOPBITS_1;
	uart_handle.Init.Parity     = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode       = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
}

void blue_pb_init_it()
{
	GPIO_InitTypeDef blue_pb_pi11;

	blue_pb_pi11.Pin = GPIO_PIN_11;
	blue_pb_pi11.Mode = GPIO_MODE_IT_RISING;
	blue_pb_pi11.Speed = GPIO_SPEED_HIGH;
	blue_pb_pi11.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOI, &blue_pb_pi11);

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 15, 0);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (state == OPENING)
		state = -1;

	state++;
}

int is_state_changed()
{
	if (state != previous_state)
		return TRUE;
	else
		return FALSE;
}

void green_led_inint()
{
	GPIO_InitTypeDef led_green_pi1;

	led_green_pi1.Pin = GPIO_PIN_1;
	led_green_pi1.Mode = GPIO_MODE_OUTPUT_PP;
	led_green_pi1.Pull = GPIO_PULLDOWN;
	led_green_pi1.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOI, &led_green_pi1);
}

void tim1_hanlder_init_no_interrupt()
{
	// enable clock tim1 in enable_clock()

	tim1_handler.Instance = TIM1;
	tim1_handler.Init.Prescaler = 54000 -1;
	tim1_handler.Init.Period = 4000 - 1; // 4000 ms is one second
	tim1_handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim1_handler.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim1_handler);
	HAL_TIM_Base_Start(&tim1_handler);
}

/*
 * toogles led with 1hz freq using TIM1 in cnt up mode
 */
void flahing_open_state_mode()
{
	while (state == OPEN) {
		if (TIM1->CNT <= 1000)
			GPIOI->ODR &= ~GPIO_PIN_1;
		if (TIM1->CNT > 1000 && TIM1->CNT <= 2000)
			GPIOI->ODR |= GPIO_PIN_1;
		if (TIM1->CNT > 2000 && TIM1->CNT <= 3000)
			GPIOI->ODR &= ~GPIO_PIN_1;
		if (TIM1->CNT > 3000)
			GPIOI->ODR |= GPIO_PIN_1;
	}

}

void flahing_securing_state_mode()
{
	while (state == SECURING) {
		if (TIM1->CNT > 2000)
			GPIOI->ODR |= GPIO_PIN_1;
		else
			GPIOI->ODR &= ~GPIO_PIN_1;
	}
}

void flahing_secured_state_mode()
{
	while (state == SECURED) {
		GPIOI->ODR &= ~GPIO_PIN_1;
	}
}

void flahing_opening_state_mode()
{
	while (state == OPENING) {
		if (TIM1->CNT > 2000)
					GPIOI->ODR |= GPIO_PIN_1;
		else
			GPIOI->ODR &= ~GPIO_PIN_1;
	}

}

int main(void)
{
	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();
	enable_clocks();
	init_uart();
	blue_pb_init_it();
	green_led_inint();
	tim1_hanlder_init_no_interrupt();

	while (1)
	{
		if (is_state_changed()) {;
			if (state == OPEN) {
				printf("Entered in open sate.\n");
				flahing_open_state_mode();
				continue;
			} else if (state == SECURING) {
				printf("Entered in securing sate.\n");
				flahing_securing_state_mode();
				continue;
			} else if (state == SECURED) {
				printf("Entered in secured state.\n");
				flahing_secured_state_mode();
				continue;
			} else if (state == OPENING) {
				printf("Entered in opening state.\n");
				flahing_opening_state_mode();
				continue;
			} else {
				printf("There is some kind of error. Contact the operator.\n");
			}

			previous_state = state;
		}

	}
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&uart_handle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* activate the OverDrive to reach the 216 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
  * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
  *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20010000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
