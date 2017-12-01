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
#include <stdio.h>
#include <stdlib.h>

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */
/* Private typedef -----------------------------------------------------------*/

// stores a defined pin and the corresponding pin
typedef struct {
	GPIO_InitTypeDef pin;
	GPIO_TypeDef *port;
} pin_w_port_t;

// enum used for the array of 7seg display
typedef enum  {
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	DOT
} disp_element;

/* Private define ------------------------------------------------------------*/

#define TRUE 1
#define FALSE 0
#define DISP_ARR_SIZE 8 // size of the array string the elements for 7seg disp

/* Private variables ---------------------------------------------------------*/

UART_HandleTypeDef uart_handle;
int stopable = FALSE; // monitors button state
uint32_t tickstart = 0;

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

/*
 * monitors button state change and deals penalty if user reacted before due time
 * takes delay as ms, button to monitor, and button's port
 * returns 1 if button was hit prematurely
 * returns 0 if signal can be turned on to start measuring user reaction
 */
int game_delay(uint32_t delay, pin_w_port_t button);

/*
 * function configures and initializes a pin
 * takes initializers as args
 * returns the pin packed with its port
 */
pin_w_port_t create_init_pin_w_port(uint16_t pin_nr, uint32_t mode, uint32_t resistor, uint32_t speed, GPIO_TypeDef *port);

/*
 * sets all pins of the passed array
 * takes the array and its size as params
 */
void turn_on_display(pin_w_port_t arr[], int size);

/*
 * resets all pins of the passed array
 * takes the array and its size as params
 */
void turn_off_display(pin_w_port_t arr[], int size);

/*
 * sets up display structure for the 7 seg disp
 * takes the desired display figure
 * enumerates all array elements and sets if are desired to display (ture - to disp, false - to hide)
 * this fucntion is used in the disp_number() function for configuration
 */
void disp_set_up(
		int num_to_display,
		disp_element A,
		int state_a,
		disp_element B,
		int state_b,
		disp_element C,
		int state_c,
		disp_element D,
		int state_d,
		disp_element E,
		int state_e,
		disp_element F,
		int state_f,
		disp_element G,
		int state_g,
		pin_w_port_t pin_w_port_arr[],
		int size);

/*
 * displays the requested character
 * takes the char to display as int, the 7seg display's array, and its size
 */
void disp_number(int num, pin_w_port_t pin_w_port_arr[], int size);

int main(void)
{
	uint32_t start = 0;             // marks clock tick when user started to measure reaction
	uint32_t finish = 0;            // marks clock tick when user finished to measure reaction
	int counter = 0;                // marks round nr.
	uint32_t result_arr[3];         // holds results for each round
	uint32_t result = 0;            // holds the result the actual round
	uint32_t rnd_delay_skalar = 0;  // holds random number
	int skip = 0;                   // flag if user stops reaction timer prematurely

	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	/* STM32F7xx HAL library initialization*/
	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();

	// init port clock and rnd clock
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOF_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_RNG_CLK_ENABLE();

	// init indicator led and external button
	pin_w_port_t led_a0 = create_init_pin_w_port(GPIO_PIN_0, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOA);
	pin_w_port_t button_a5 = create_init_pin_w_port(GPIO_PIN_6, GPIO_MODE_INPUT, GPIO_PULLUP, GPIO_SPEED_HIGH, GPIOF);

	// init 7seg display pins and array
	pin_w_port_t disp_ad0 = create_init_pin_w_port(GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOC);
	pin_w_port_t disp_bd1 = create_init_pin_w_port(GPIO_PIN_6, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOC);
	pin_w_port_t disp_cd4 = create_init_pin_w_port(GPIO_PIN_0, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOI);
	pin_w_port_t disp_dd6 = create_init_pin_w_port(GPIO_PIN_6, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOH);
	pin_w_port_t disp_ed7 = create_init_pin_w_port(GPIO_PIN_3, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOI);
	pin_w_port_t disp_fd8 = create_init_pin_w_port(GPIO_PIN_8, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOA);
	pin_w_port_t disp_gd10 = create_init_pin_w_port(GPIO_PIN_2, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOI);
	pin_w_port_t disp_dotd5 = create_init_pin_w_port(GPIO_PIN_7, GPIO_MODE_OUTPUT_PP, GPIO_PULLDOWN, GPIO_SPEED_HIGH, GPIOG);

	pin_w_port_t disp_arr[] = {disp_ad0, disp_bd1, disp_cd4, disp_dd6, disp_ed7, disp_fd8, disp_gd10, disp_dotd5};

	// conf and init uart handler
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);

	// conf and init rng
	RNG_HandleTypeDef rndCfg;
	rndCfg.Instance = RNG;
	HAL_RNG_Init(&rndCfg);

	// displays "hello" on 7seg disp
	disp_number('h', disp_arr, DISP_ARR_SIZE);
	HAL_Delay(400);
	disp_number('e', disp_arr, DISP_ARR_SIZE);
	HAL_Delay(400);
	disp_number('l', disp_arr, DISP_ARR_SIZE);
	HAL_Delay(400);
	turn_off_display(disp_arr, DISP_ARR_SIZE);
	HAL_Delay(300);
	disp_number('l', disp_arr, DISP_ARR_SIZE);
	HAL_Delay(400);
	disp_number(0, disp_arr, DISP_ARR_SIZE);
	HAL_Delay(400);
	turn_off_display(disp_arr, DISP_ARR_SIZE);
	HAL_Delay(400);
	disp_number(1, disp_arr, DISP_ARR_SIZE);

	//Output a message using printf function
	printf("\n------------------WELCOME------------------\r\n"
		   "**********in STATIC reaction game**********\r\n\n"
		   "Let's play a game! Are you ready?\r\n\n"
		   "Your will have three rounds.\n"
		   "Press the button again after the led is lit to see your reaction speed!\n"
		   "If your press before due time, your will get a penalty...\n");

	while (1) {

		GPIOA->ODR |= 1;                                                    // lits indicator led
		printf("Smash the button to start round!\n");
		HAL_RNG_GenerateRandomNumber(&rndCfg, &rnd_delay_skalar);
		rnd_delay_skalar = (rnd_delay_skalar % 10 / 3) + 1;
		while (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_6)) {};                     // waits for button press
		skip = game_delay(1000 * rnd_delay_skalar, button_a5);              // starts delay time with random length
		while (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_6) == 0 && !stopable) {};   // prevents user to cheat with kept button on 0
		stopable = FALSE;
		GPIOA->ODR |= 1;                                                    // indicates for user to push button
		start = HAL_GetTick();
		while (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_6)) {};
		finish = HAL_GetTick();
		while (!HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_6)){};
		printf("Start time: %ld\n", start);
		printf("Finish time: %ld\n", finish);
		if (skip)
			result = 1000;
		else
			result = finish - start;
		result_arr[counter++] = result;
		if (counter == 1)
			disp_number(2, disp_arr, DISP_ARR_SIZE);
		else if (counter == 2)
			disp_number(3, disp_arr, DISP_ARR_SIZE);
		else if (counter == 3) {
			disp_number(0, disp_arr, DISP_ARR_SIZE);
			break;
		}
		printf("Reaction time: %ld\n", result);
		GPIOA->ODR &= 0;
	}

	printf("This is the end of the game.\n");
	printf("Results: \n");
	uint32_t sum = 0;
	for (int i = 0; i < 3; ++i) {
		printf("Results: %d: %u\n", i, (unsigned int) result_arr[i]);
		sum += result_arr[i];
	}

	// converting float to a printable format
	double avg = (double) sum / 3;
	int int_part_of_avg = (int) avg / 1;
	int float_part_of_avg = (int) ((avg - int_part_of_avg) * 1000);

	printf("Avg: %d.%d\n", int_part_of_avg, float_part_of_avg);
	printf("Hit reset to start a new game.\n");
}

int game_delay(uint32_t delay, pin_w_port_t button)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	tickstart = HAL_GetTick();

	for (int i = delay; i > 0; --i) { 	// clocks away regardless of how user handles button
		HAL_Delay(1);
		if (HAL_GPIO_ReadPin(button.port, button.pin.Pin) == 1) {
			stopable = TRUE; 			// detect state change of button
		}

		if (HAL_GPIO_ReadPin(button.port, button.pin.Pin) == 0 && stopable) {
			printf("Your have to wait for start.\n");
			stopable = TRUE;
			return 1;					// if user stops action before led signal, he got penalized
		}
	}
	return 0;							// quit if delay timer clocked away w/o problems
}

pin_w_port_t create_init_pin_w_port(uint16_t pin_nr, uint32_t mode, uint32_t resistor, uint32_t speed, GPIO_TypeDef *port)
{
	pin_w_port_t *new_pin_w_port = (pin_w_port_t*)  malloc(sizeof(pin_w_port_t));
	GPIO_InitTypeDef *new_pin = (GPIO_InitTypeDef*) malloc(sizeof(GPIO_InitTypeDef));
	new_pin->Pin = pin_nr;
	new_pin->Mode = mode;
	new_pin->Pull = resistor;
	new_pin->Speed = speed;
	new_pin_w_port->pin = *new_pin;
	new_pin_w_port->port = port;

	HAL_GPIO_Init(port, new_pin);

	return *new_pin_w_port;
}


void turn_on_display(pin_w_port_t arr[], int size) {
	for (int i = 0; i < size; ++i) {
		HAL_GPIO_WritePin(arr[i].port, arr[i].pin.Pin, GPIO_PIN_SET);
		HAL_Delay(400);
		HAL_GPIO_WritePin(arr[i].port, arr[i].pin.Pin, GPIO_PIN_RESET);
	}
}

void turn_off_display(pin_w_port_t arr[], int size) {
	for (int i = 0; i < size; ++i) {
		HAL_GPIO_WritePin(arr[i].port, arr[i].pin.Pin, GPIO_PIN_RESET);
	}
}

void disp_set_up(
		int num_to_display,
		disp_element A,
		int state_a,
		disp_element B,
		int state_b,
		disp_element C,
		int state_c,
		disp_element D,
		int state_d,
		disp_element E,
		int state_e,
		disp_element F,
		int state_f,
		disp_element G,
		int state_g,
		pin_w_port_t pin_w_port_arr[],
		int size)
{
	turn_off_display(pin_w_port_arr, DISP_ARR_SIZE);
	if (state_a)
		pin_w_port_arr[A].port->ODR |= pin_w_port_arr[A].pin.Pin;
	if (state_b)
		pin_w_port_arr[B].port->ODR |= pin_w_port_arr[B].pin.Pin;
	if (state_c)
		pin_w_port_arr[C].port->ODR |= pin_w_port_arr[C].pin.Pin;
	if (state_d)
		pin_w_port_arr[D].port->ODR |= pin_w_port_arr[D].pin.Pin;
	if (state_e)
		pin_w_port_arr[E].port->ODR |= pin_w_port_arr[E].pin.Pin;
	if (state_f)
		pin_w_port_arr[F].port->ODR |= pin_w_port_arr[F].pin.Pin;
	if (state_g)
		pin_w_port_arr[G].port->ODR |= pin_w_port_arr[G].pin.Pin;

	pin_w_port_arr[DOT].port->ODR |= pin_w_port_arr[DOT].pin.Pin;

}

void disp_number(int num, pin_w_port_t pin_w_port_arr[], int size)
{
	switch (num) {
		case 0:	// 0, "O"
			disp_set_up(0, A, TRUE, B, TRUE, C, TRUE, D, TRUE, E, TRUE, F, TRUE, G, FALSE, pin_w_port_arr, size);
			break;
		case 1: // 1
			disp_set_up(0, A, FALSE, B, TRUE, C, TRUE, D, FALSE, E, FALSE, F, FALSE, G, FALSE, pin_w_port_arr, size);
			break;
		case 2:	// 2
			disp_set_up(0, A, TRUE, B, TRUE, C, FALSE, D, TRUE, E, TRUE, F, FALSE, G, TRUE, pin_w_port_arr, size);
			break;
		case 3:	// 3
			disp_set_up(0, A, TRUE, B, TRUE, C, TRUE, D, TRUE, E, FALSE, F, FALSE, G, TRUE, pin_w_port_arr, size);
			break;
		/*case 4:
			disp_set_up(0, A, FALSE, B, TRUE, C, TRUE, D, FALSE, E, FALSE, F, TRUE, G, TRUE, pin_w_port_arr, size);
			break;
		case 5:
			disp_set_up(0, A, TRUE, B, FALSE, C, TRUE, D, TRUE, E, FALSE, F, TRUE, G, TRUE, pin_w_port_arr, size);
			break;
		case 6:
			disp_set_up(0, A, TRUE, B, FALSE, C, TRUE, D, TRUE, E, TRUE, F, TRUE, G, TRUE, pin_w_port_arr, size);
			break;
		case 7:
			disp_set_up(0, A, TRUE, B, TRUE, C, TRUE, D, FALSE, E, FALSE, F, FALSE, G, FALSE, pin_w_port_arr, size);
			break;
		case 8:
			disp_set_up(0, A, TRUE, B, TRUE, C, TRUE, D, TRUE, E, TRUE, F, TRUE, G, TRUE, pin_w_port_arr, size);
			break;
		case 9:
			disp_set_up(0, A, TRUE, B, TRUE, C, TRUE, D, TRUE, E, FALSE, F, TRUE, G, TRUE, pin_w_port_arr, size);
			break;*/
		case 'h': // "H"
			disp_set_up(0, A, FALSE, B, TRUE, C, TRUE, D, FALSE, E, TRUE, F, TRUE, G, TRUE, pin_w_port_arr, size);
			break;
		case 'e': // "E"
			disp_set_up(0, A, TRUE, B, FALSE, C, FALSE, D, TRUE, E, TRUE, F, TRUE, G, TRUE, pin_w_port_arr, size);
			break;
		case 'l': // "L"
			disp_set_up(0, A, FALSE, B, FALSE, C, FALSE, D, TRUE, E, TRUE, F, TRUE, G, FALSE, pin_w_port_arr, size);
			break;
		default: // 0, "0"
			disp_set_up(0, A, FALSE, B, FALSE, C, FALSE, D, FALSE, E, FALSE, F, FALSE, G, FALSE, pin_w_port_arr, size);
	}
}

/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
	/* Place your implementation of fputc here */
	/* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
	HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);

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
static void SystemClock_Config(void) {
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
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
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
static void CPU_CACHE_Enable(void) {
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
