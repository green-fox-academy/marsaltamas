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
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

UART_HandleTypeDef uart_handle;
RNG_HandleTypeDef rndCfg;
TIM_HandleTypeDef tim1_handler;
TIM_HandleTypeDef tim2_handler;

int rnd_num; // used as the slot to store generated random num

/* Private function prototypes -----------------------------------------------*/

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private functions ---------------------------------------------------------*/

// init green led on board (pi1)
void greenLedInintGPIO();
/*
 *  init blue bp on board (pi11)
 *  this button is input, nopull in gpio mode
 */
void bluePbInit();

// enable each clock used
void enable_clocks();

void UART_Init();

void Rng_Init();

// returns a rnd integer number using RNG of the board
int get_rnd_num();

// can toogle led on given cnt reg value
void tim1_hanlder_init_no_interrupt();

// calls interrupt in base mode, after period elapsed
void TIM2_IRQHandler();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void tim2_handler_init();

int main(void)
{
  MPU_Config();

  /* Enable the CPU Cache */
  CPU_CACHE_Enable();

  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the System clock to have a frequency of 216 MHz */
  SystemClock_Config();

  enable_clocks();
  greenLedInintGPIO();
  bluePbInit();
  UART_Init();
  Rng_Init();
  tim1_hanlder_init_no_interrupt();
  tim2_handler_init();

	while (1)
	{

		/* toogles led with 1hz freq using TIM1 in cnt up mode
		if (TIM1->CNT > 3999)
			GPIOI->ODR |= GPIO_PIN_1;
		else
			GPIOI->ODR &= ~GPIO_PIN_1;
		*/

		/* if button pushed, led turns on
		if (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11)) {
			HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_SET);
			printf("light is on\n");
		}

		HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, GPIO_PIN_RESET);
		*/

		/* rng pringint and hal get tick
		for (int i = 0; i < 10; ++i) {
			printf("random %d: %d\n", i, get_rnd_num());
			printf("hal systick: %ld\n", HAL_GetTick());
			HAL_Delay(300);
		}
		*/
	}
}

PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(&uart_handle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}

void enable_clocks()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_RNG_CLK_ENABLE();
	__HAL_RCC_TIM1_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
}

// these pins are communicating with the pc
void UART_Init()
{
	GPIO_InitTypeDef pinTx_pa9;	// pin for transmission

	pinTx_pa9.Pin = GPIO_PIN_9;
	pinTx_pa9.Mode = GPIO_MODE_AF_PP;
	pinTx_pa9.Alternate = GPIO_AF7_USART1;
	pinTx_pa9.Pull = GPIO_PULLUP;
	pinTx_pa9.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &pinTx_pa9);

	GPIO_InitTypeDef pinRx_pb7;	// pin for receiving info

	pinRx_pb7.Pin = GPIO_PIN_7;
	pinRx_pb7.Mode = GPIO_MODE_AF_PP;
	pinRx_pb7.Alternate = GPIO_AF7_USART1;
	pinRx_pb7.Pull = GPIO_PULLUP;
	pinRx_pb7.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOB, &pinRx_pb7);

	uart_handle.Instance         = USART1;
	uart_handle.Init.BaudRate    = 115200;
	uart_handle.Init.WordLength  = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits    = UART_STOPBITS_1;
	uart_handle.Init.Parity      = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl   = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode        = UART_MODE_TX_RX;

	HAL_UART_Init(&uart_handle);
}


void Rng_Init()
{
	rndCfg.Instance = RNG;
	HAL_RNG_Init(&rndCfg);
}

int get_rnd_num()
{
	HAL_RNG_GenerateRandomNumber(&rndCfg, &rnd_num);

	return rnd_num;
}

void greenLedInintGPIO()
{
	GPIO_InitTypeDef led_green_pi1;

	led_green_pi1.Pin = GPIO_PIN_1;
	led_green_pi1.Mode = GPIO_MODE_OUTPUT_PP;
	led_green_pi1.Pull = GPIO_PULLDOWN;
	led_green_pi1.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOI, &led_green_pi1);
}

void bluePbInit()
{
	GPIO_InitTypeDef blue_pb_pi11;

	blue_pb_pi11.Pin = GPIO_PIN_11;
	blue_pb_pi11.Mode = GPIO_MODE_INPUT;
	blue_pb_pi11.Speed = GPIO_SPEED_HIGH;
	blue_pb_pi11.Pull = GPIO_NOPULL;

	HAL_GPIO_Init(GPIOI, &blue_pb_pi11);
}

// TIM1 used to toogle led in 1000 ms feq
void tim1_hanlder_init_no_interrupt()
{
	// enable clock tim1 in enable_clock()

	tim1_handler.Instance = TIM1;
	tim1_handler.Init.Prescaler = 54000 -1;
	tim1_handler.Init.Period = 8000 - 1;
	tim1_handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim1_handler.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim1_handler);
	HAL_TIM_Base_Start(&tim1_handler);
}

// used in interrupt mode for sending message to uart in every 500 ms
void tim2_handler_init()
{
	// enable clock tim2 in enable_clock()

	tim2_handler.Instance = TIM2;
	tim2_handler.Init.Prescaler = 54000 - 1;
	tim2_handler.Init.Period = 1000 -1;
	tim2_handler.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim2_handler.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim2_handler);
	HAL_TIM_Base_Start_IT(&tim2_handler);
	//HAL_TIM_PWM_Start_IT(&tim2_handler);

	TIM_OC_InitTypeDef oc_conf_tim2;

	//oc_conf_tim2.OCMode = TIM_OCMODE_PWM1;
	//oc_conf_tim2.Pulse = 2500;

	//HAL_TIM__ConfigChannel(&tim2_handler, &oc_conf_tim2, TIM_CHANNEL_1);

	//HAL_TIM_PWM_Start(&tim2_handler, TIM_CHANNEL_1);

	HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler()
{
	HAL_TIM_IRQHandler(&tim2_handler);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	printf("period elapsed called\n");

	if (!HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_1))
		GPIOI->ODR |= GPIO_PIN_1;
	else
		GPIOI->ODR &= ~GPIO_PIN_1;
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
