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
#include <stdlib.h>
#include <string.h>

/**
 * Constants
 */
#define BUFFER_SIZE					32
#define ERROR_FLASH_COUNT			3

/**
 * PIN configurations for LEDs
 */
#define LED_GREEN_PORT				GPIOI
#define LED_GREEN_PIN				GPIO_PIN_1
#define LED_ERROR_PORT				GPIOA
#define LED_ERROR_PIN				GPIO_PIN_15

#define __LED_GREEN__				LED_GREEN_PORT, LED_GREEN_PIN
#define __LED_ERROR__				LED_ERROR_PORT, LED_ERROR_PIN

/**
 * PIN configurations for UARTs
 */
#define UART_CPY_INSTANCE			USART6
#define UART_CPY_CLK_START()		__HAL_RCC_USART6_CLK_ENABLE()
#define UART_CPY_CLK_STOP()			__HAL_RCC_USART6_CLK_DISABLE()
#define UART_CPY_GPIO_CLK_START()	__HAL_RCC_GPIOC_CLK_ENABLE()
#define UART_CPY_GPIO_CLK_STOP()	__HAL_RCC_GPIOC_CLK_DISABLE()
#define UART_CPY_GPIO_PORT			GPIOC
#define UART_CPY_GPIO_TX_PIN		GPIO_PIN_6
#define UART_CPY_GPIO_RX_PIN		GPIO_PIN_7

#define UART_INSTANCE				USART1
#define UART_CLK_START()			__HAL_RCC_USART1_CLK_ENABLE()
#define UART_CLK_STOP()				__HAL_RCC_USART1_CLK_DISABLE()
#define UART_GPIO_TX_PORT			GPIOA
#define UART_GPIO_TX_PIN			GPIO_PIN_9
#define UART_GPIO_TX_CLK_START()	__HAL_RCC_GPIOA_CLK_ENABLE()
#define UART_GPIO_TX_CLK_STOP()		__HAL_RCC_GPIOA_CLK_DISABLE()
#define UART_GPIO_RX_PORT			GPIOB
#define UART_GPIO_RX_PIN			GPIO_PIN_7
#define UART_GPIO_RX_CLK_START()	__HAL_RCC_GPIOB_CLK_ENABLE()
#define UART_GPIO_RX_CLK_STOP()		__HAL_RCC_GPIOB_CLK_DISABLE()

/**
 * Alternative usage of 0 and 1 bits
 */
#define ON							GPIO_PIN_SET
#define OFF							GPIO_PIN_RESET

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/**
 * The definitions of the commands
 */
const char *COMMAND_ON = "on";
const char *COMMAND_OFF = "off";
const char *COMMAND_MANUAL = "man";

typedef struct {
    uint8_t *head, *tail;
    uint8_t buffer[BUFFER_SIZE];
} CB_TypeDef;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef UartHandle;
UART_HandleTypeDef UartHandleCopy;
TIM_HandleTypeDef LedFlashingTimerHandle;
TIM_OC_InitTypeDef PWMConfigHandle;

volatile CB_TypeDef buffer;

volatile uint8_t command[BUFFER_SIZE];
volatile uint8_t newCommandSet;
volatile uint8_t errorFlashCount;

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

static void ConfigurePeripherials(void);
static void UART_Init(void);
static void UART_Init_IT(void);
static void GPIO_LED_Init(void);
static void UART_StartListening(void);
static void UART_EvalCommand(void);
static void ClearCommand(void);
static void ERROR_PWM_Init(void);
static void State_Init(void);
static void ERROR_FlashLed(uint8_t nTimes);
static void BannerPrint(void);
static void ManualPrint(void);
static uint8_t __bufferReadNext(void);

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {

    ConfigurePeripherials();
    BannerPrint();
    ManualPrint();
    UART_StartListening();
    while (1) {
        if (!newCommandSet) {
            continue;
        }
        if (strcmp(COMMAND_ON, (char*) command) == 0) {
            HAL_GPIO_WritePin(__LED_GREEN__, ON);
        }
        else if (strcmp(COMMAND_OFF, (char*) command) == 0) {
            HAL_GPIO_WritePin(__LED_GREEN__, OFF);
        }
        else if (strcmp(COMMAND_MANUAL, (char*) command) == 0) {
            ManualPrint();
        }
        else {
            ERROR_FlashLed(ERROR_FLASH_COUNT);
            printf("Unknown command: %s\r\n", command);
        }
        ClearCommand();
    }
}

/**
 * Starts continuous listening on UART (USART1 - this is the PC connection)
 * using interrupts - non-blocking function.
 *
 * The data from USART1 is continuously written to the ring buffer, char-by-char.
 */
static void UART_StartListening(void) {
    HAL_UART_Receive_IT(&UartHandle, buffer.head, 1);
}

/**
 * The UART interrupt's callback once a byte got read into the ring buffer. Updates
 * the buffer's head pointer and initiates the receive of the next character, then evaluates
 * if there's any command in the buffer.
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (buffer.head == &buffer.buffer[BUFFER_SIZE - 1]) {
        buffer.head = (uint8_t*) &buffer.buffer[0];
    }
    else {
        buffer.head++;
    }
    UART_EvalCommand();
    HAL_UART_Receive_IT(&UartHandle, buffer.head, 1);
}

/**
 * Clears the command variable once it's processed.
 */
static void ClearCommand(void) {
    command[0] = '\0';
    newCommandSet = 0;
}

/**
 * Checks if the last read byte was a new line character. If so, extracts the command
 * to the command global variable and sets the flag for the main routine to process it.
 */
static void UART_EvalCommand(void) {
    uint8_t *prevHead = (buffer.head) - 1;
    if (*prevHead != '\n') {
        return;
    }

    int len = prevHead - buffer.tail;
    if (len < 0) {
        len += BUFFER_SIZE;
    }

    for (int i = 0; i < len; i++) {
        command[i] = __bufferReadNext();
    }

    // we remove the unread line feed character
    __bufferReadNext();
    command[len] = '\0';
    newCommandSet = 1;
}

/**
 * Reads a single byte from the circular buffer maintaining the tail pointer.
 * If there's nothing to read, returns value 0.
 */
static uint8_t __bufferReadNext() {
    if (buffer.tail == buffer.head) {
        return 0;
    }

    uint8_t res = *buffer.tail;
    if (buffer.tail == &buffer.buffer[BUFFER_SIZE - 1]) {
        buffer.tail = (uint8_t*) &buffer.buffer[0];
    }
    else {
        buffer.tail++;
    }
    return res;
}

/**
 * Starts the PWM to flash the error LED ERROR_FLASH_COUNT times.
 */
static void ERROR_FlashLed(uint8_t nTimes) {
    errorFlashCount = nTimes;
    HAL_TIM_PWM_Start_IT(&LedFlashingTimerHandle, TIM_CHANNEL_1);
}

/**
 * Callback for the PWM pulse finish to count the number of the
 * flashes.
 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
    if (--errorFlashCount == 0) {
        HAL_TIM_PWM_Stop_IT(&LedFlashingTimerHandle, TIM_CHANNEL_1);
    }
}

/**
 * Extracted from the main - configures the peripherials.
 */
static void ConfigurePeripherials(void) {

    /* Configure the MPU attributes as Write Through */
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

    /**
     * Configure UART with interrupts enabled
     */
    UART_Init_IT();

    /**
     * Configure LED output
     */
    GPIO_LED_Init();

    /**
     * Setup error flasher timer PWM
     */
    ERROR_PWM_Init();

    /**
     * Setup initial state of variables
     */
    State_Init();
}

/**
 * Initializes the PWM with F=3Hz (T=1/3s), resolution: 10000, duty cycle=50%
 */
static void ERROR_PWM_Init(void) {
    __HAL_RCC_TIM2_CLK_ENABLE()
    ;

    LedFlashingTimerHandle.Instance = TIM2;
    LedFlashingTimerHandle.Init.AutoReloadPreload =
    TIM_AUTORELOAD_PRELOAD_DISABLE;
    LedFlashingTimerHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    LedFlashingTimerHandle.Init.Period = 10000;
    LedFlashingTimerHandle.Init.Prescaler = 3598;
    HAL_TIM_PWM_Init(&LedFlashingTimerHandle);

    PWMConfigHandle.OCMode = TIM_OCMODE_PWM1;
    PWMConfigHandle.Pulse = 5000;
    HAL_TIM_PWM_ConfigChannel(&LedFlashingTimerHandle, &PWMConfigHandle,
    TIM_CHANNEL_1);

    HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x00);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/**
 * Initializes the initial state of the variables (ring buffer, command, etc.)
 */
static void State_Init() {
    buffer.head = buffer.tail = (uint8_t*) &buffer.buffer[0];
    command[0] = '\0';
    newCommandSet = 0;
    errorFlashCount = 3;
}

/**
 * Initializes the error LED on port LED_ERROR_PORT, pin LED_ERROR_PIN. This
 * LED is driven by the PWM.
 */
static void GPIO_LED_Init(void) {
    __HAL_RCC_GPIOA_CLK_ENABLE()
    ;
    GPIO_InitTypeDef ledPin;
    ledPin.Mode = GPIO_MODE_AF_PP;
    ledPin.Alternate = GPIO_AF1_TIM2;
    ledPin.Pull = GPIO_NOPULL;
    ledPin.Speed = GPIO_SPEED_HIGH;
    ledPin.Pin = LED_ERROR_PIN;
    HAL_GPIO_Init(LED_ERROR_PORT, &ledPin);

    BSP_LED_Init(LED_GREEN);

    HAL_GPIO_WritePin(__LED_ERROR__, OFF);
    HAL_GPIO_WritePin(__LED_GREEN__, OFF);
}

/**
 * Initializes the UART channels. Note that there are 2: USART6 for inspection
 * and USART1 for PC connection (UART through USB).
 */
static void UART_Init() {

    UART_CPY_GPIO_CLK_START()
    ;
    GPIO_InitTypeDef pinCfg;
    pinCfg.Alternate = GPIO_AF8_USART6;
    pinCfg.Mode = GPIO_MODE_AF_PP;
    pinCfg.Pull = GPIO_PULLUP;
    pinCfg.Speed = GPIO_SPEED_HIGH;
    pinCfg.Pin = UART_CPY_GPIO_RX_PIN | UART_CPY_GPIO_TX_PIN;
    HAL_GPIO_Init(UART_CPY_GPIO_PORT, &pinCfg);

    UART_CPY_CLK_START()
    ;
    UartHandleCopy.Init.BaudRate = 115200;
    UartHandleCopy.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandleCopy.Init.StopBits = UART_STOPBITS_1;
    UartHandleCopy.Init.Parity = UART_PARITY_NONE;
    UartHandleCopy.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandleCopy.Init.Mode = UART_MODE_TX_RX;
    UartHandleCopy.Instance = UART_CPY_INSTANCE;
    HAL_UART_Init(&UartHandleCopy);

    UART_GPIO_RX_CLK_START()
    ;
    pinCfg.Alternate = GPIO_AF7_USART1;
    pinCfg.Pin = UART_GPIO_RX_PIN;
    HAL_GPIO_Init(UART_GPIO_RX_PORT, &pinCfg);

    UART_GPIO_TX_CLK_START()
    ;
    pinCfg.Pin = UART_GPIO_TX_PIN;
    HAL_GPIO_Init(UART_GPIO_TX_PORT, &pinCfg);

    UART_CLK_START()
    ;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;
    UartHandle.Instance = UART_INSTANCE;
    HAL_UART_Init(&UartHandle);
}

/**
 * Initiates UART and enables interrupt
 */
static void UART_Init_IT() {
    UART_Init();
    HAL_NVIC_SetPriority(USART1_IRQn, 0x0f, 0x0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
}

static void BannerPrint() {
    printf("\r\n\r\n");
    printf("|==================================================================================================|\r\n");
    printf("|  #####                                                                                           |\r\n");
    printf("| #     # ###### #####  #   ##   #         #    #  ####  #####  #    #  ####  #    #  ####  #####  |\r\n");
    printf("| #       #      #    # #  #  #  #         #    # #    # #    # #   #  #      #    # #    # #    # |\r\n");
    printf("|  #####  #####  #    # # #    # #         #    # #    # #    # ####    ####  ###### #    # #    # |\r\n");
    printf("|       # #      #####  # ###### #         # ## # #    # #####  #  #        # #    # #    # #####  |\r\n");
    printf("| #     # #      #   #  # #    # #         ##  ## #    # #   #  #   #  #    # #    # #    # #      |\r\n");
    printf("|  #####  ###### #    # # #    # ######    #    #  ####  #    # #    #  ####  #    #  ####  #      |\r\n");
    printf("|==================================================================================================|\r\n");
    printf("\r\n");
}

static void ManualPrint(void) {
    printf("Usage: \r\n");
    printf("\ton\\n\tturns the green LED on\r\n");
    printf("\toff\\n\tturns the green LED off\r\n");
    printf("\tman\\n\tprints this manual\r\n");
}

/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
    /* Place your implementation of fputc here */
    /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
    HAL_UART_Transmit(&UartHandle, (uint8_t *) &ch, 1, 0xFFFF);
    HAL_UART_Transmit(&UartHandleCopy, (uint8_t *) &ch, 1, 0xFFFF);
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
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1
            | RCC_CLOCKTYPE_PCLK2);
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
