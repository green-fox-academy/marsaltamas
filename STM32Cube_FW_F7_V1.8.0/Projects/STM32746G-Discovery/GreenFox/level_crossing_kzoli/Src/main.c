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

TIM_HandleTypeDef Tim2HzHandle;

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/**
 * The state identifiers
 */
typedef enum {
    STATE_OPEN,
    STATE_SECURING,
    STATE_SECURED,
    STATE_OPENING
} State;

typedef struct {
        /* Holds the identifier of the actual state */
        State state;

        /* Holds the identifier of the next state (which state should be
         * loaded after the current one) */
        State nextState;

        /* The duration of the state in number of the timer periods. In
         * OPEN and SECURED state this is infinite, for that i use 0 value */
        uint8_t timerPeriodCounts;

        /* The time duration between toggling the LED in the actual state
         * The the SECURED state should not flash the LEDs, for that i use 0
         * value */
        uint8_t ledTogglePeriodCounts;

} State_Config;

/* Private define ------------------------------------------------------------*/
#define TIMER_2HZ   TIM2

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef UartHandle;
TIM_HandleTypeDef Tim2HzHandle;

/**
 * The state configuration for the actual state
 */
volatile State_Config _currentState;

/**
 * The counter, which counts the passed time (timer periods)
 */
volatile uint8_t _periodCounter;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

static void Peripherals_Config(void);
static void Tim2Hz_Config_IT(void);
static void Tim2Hz_Start_IT(void);
static void Tim2Hz_Stop_IT(void);
static void State_Start(State newState);
static void UART_Config(void);
/* Private functions ---------------------------------------------------------*/


void TIM2_IRQHandler(void) {
    HAL_TIM_IRQHandler(&Tim2HzHandle);
}

void EXTI15_10_IRQHandler(void) {
    HAL_GPIO_EXTI_IRQHandler(KEY_BUTTON_PIN);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim) {
    if (htim->Instance == TIM2) {
        __HAL_RCC_TIM2_CLK_ENABLE();
    }
}

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
    /*
     * TASK SUMMARY:
     * You need to implement a system which simulates a railway level crossing.
     *
     * SPECIFICATION:
     * 1. The initial state of the system is OPEN, so it allows cars passing. In this state
     *    the LED_GREEN should be flashing with 0.5Hz, 50% duty cycle
     * 2. When the system gets a signal that a train is approaching the crossing (blue
     *    button click) it has to enter into SECURING state. In SECURING state the system
     *    has to close the barrier which this takes exactly 5 seconds. In this state the
     *    LED_GREEN should be flashing with 1Hz, 50% duty cycle. During this time the system
     *    should not react to any further signal (blue button click).
     * 3. Once the barrier is down the system enters into SECURED state. In this state the
     *    LED_GREEN is turned constantly off.
     * 4. When the system gets a signal that a train has left the crossing (blue button
     *    click) it switches to OPENING state: lifts the barrier which takes exactly 6
     *    seconds (it's a heavy barrier so it takes more time to lift). In this state the
     *    LED_GREEN is flashing with 1Hz, 50% duty cycle. During this time the system
     *    should not react to any further signal (blue button click). Once the barrier
     *    is up, the system get's back to it's initial, OPEN state (point 1.).
     *
     * NON FUNCTIONAL REQUIREMENTS:
     * 1. You cannot read the state of the blue button, use interrupts!
     * 2. You should use at least 1 timer peripheral
     * 3. Try to avoid the use of blocking waiting mechanisms (like HAL_Delay())
     * 4. Using PWM on LED_GREEN is possible, but not required. Note that you have no
     *    timer channel to LED_GREEN, so to drive it from PWM you should turn on the LED
     *    in every timer period end interrupt, and turn it off in every PWM pulse end
     *    interrupt.
     * 5. When you enter to any state, you should report this on USART1 peripheral. You
     *    can use BSP_COM_Init() to initialize this, and a serial monitor to read these
     *    reports. It should look something like this after reset and a train crossing:
     *
     *    Entered in OPEN state         // some time later a click comes
     *    Entered in SECURING state
     *    Entered in SECURED state      // some time later a click comes
     *    Entered in OPENING state
     *    Entered in OPEN state
     */

    /**
     * I externalized the peripherals initialization to the function below.
     */
    Peripherals_Config();

    /**
     * So i'm initiating my app with STATE_OPEN as described above. After this point,
     * the further actions will be managed by the interrupt routines
     */
    State_Start(STATE_OPEN);
    while (1) {}
}

/**
 * This function manages the state change and configure the state data
 */
static void State_Start(State newState) {
    // I stop the timer
    Tim2Hz_Stop_IT();

    // I set the new state
    _currentState.state = newState;
    switch (newState) {
        case STATE_OPEN:
            printf("Entering OPEN state\r\n");          // send the string to UART according to the specs
            _currentState.nextState = STATE_SECURING;   // the next state is STATE_SECURING
            _currentState.ledTogglePeriodCounts = 2;    // 0.5Hz flashing, so 2*0.5sec period needed to toggle the LED
            _currentState.timerPeriodCounts = 0;        // the state remains until external interrupt
            break;
        case STATE_SECURING:
            printf("Entering SECURING state\r\n");      // send the string to UART according to the specs
            _currentState.nextState = STATE_SECURED;    // the next state is STATE_SECURED
            _currentState.ledTogglePeriodCounts = 1;    // 1Hz flashing, so 1*0.5sec period needed to toggle the LED
            _currentState.timerPeriodCounts = 10;       // 5sec = 10*0.5sec (10 timer periods)
            break;
        case STATE_SECURED:
            printf("Entering SECURED state\r\n");       // send the string to UART according to the specs
            _currentState.nextState = STATE_OPENING;    // the next state is STATE_OPENING
            _currentState.ledTogglePeriodCounts = 0;    // no flashing
            _currentState.timerPeriodCounts = 0;        // the state remains until external interrupt
            break;
        case STATE_OPENING:
            printf("Entering OPENING state\r\n");       // send the string to UART according to the specs
            _currentState.nextState = STATE_OPEN;       // the next state is STATE_OPEN
            _currentState.ledTogglePeriodCounts = 1;    // 1Hz flashing, so 1*0.5sec period needed to toggle the LED
            _currentState.timerPeriodCounts = 12;       // 6sec = 12*0.5sec (12 timer periods)
            break;
    }
    // The LED should be flashed if the state is not SECURED so i start the timer with interrupts
    if (newState != STATE_SECURED) {
        Tim2Hz_Start_IT();
    }
}

static void Tim2Hz_Start_IT(void) {
    // reset the counter to (i want full periods when the timer starts, so it should count
    // from 0
    TIMER_2HZ->CNT = 0;

    // i reset the period counter
    _periodCounter = 0;

    // i turn the LED ON (beginning of the flashing)
    BSP_LED_On(LED_GREEN);

    // i start the timer with interrupts
    HAL_TIM_Base_Start_IT(&Tim2HzHandle);
}

static void Tim2Hz_Stop_IT(void) {
    // Turn the LED off
    BSP_LED_Off(LED_GREEN);
    // stop the timer
    HAL_TIM_Base_Stop_IT(&Tim2HzHandle);
}

/************************************************************
 * INTERRUPT CALLBACK FUNCTIONS BELOW
 ***********************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    // increase the period counter after every period
    _periodCounter++;

    // if the timerPeriodCounts > 0 (non infinite), and the specified periods were elapsed, switch to
    // the next state
    if (_currentState.timerPeriodCounts && _currentState.timerPeriodCounts == _periodCounter) {
        State_Start(_currentState.nextState);
        return;
    }

    // if the led should be toggled (ledTogglePeriodCounts > 0) and the _periodCount is the multiple of
    // ledTogglePeriodCounts, then i need to toggle the LEDs
    if (_currentState.ledTogglePeriodCounts && !(_periodCounter%_currentState.ledTogglePeriodCounts)) {
        BSP_LED_Toggle(LED_GREEN);
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    // I should not accept EXTI in OPENING and SECURING states
    if (_currentState.state == STATE_OPENING || _currentState.state == STATE_SECURING) {
        return;
    }
    // otherwise i need to start the next state
    State_Start(_currentState.nextState);
}

/************************************************************
 * PERIPHERIAL CONFIGURATION FUNCTIONS BELOW
 ***********************************************************/
static void Peripherals_Config(void) {
    /* This project template calls firstly two functions in order to configure MPU feature
     and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
     These functions are provided as template implementation that User may integrate
     in his application, to enhance the performance in case of use of AXI interface
     with several masters. */

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

    /* Configure a timer for 2Hz */
    Tim2Hz_Config_IT();

    /* Configure UART to PC for reporting states */
    UART_Config();

    /* Configure button for interrupt */
    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);

    /* Enable LED */
    BSP_LED_Init(LED_GREEN);
}

/**
 * LED 1Hz  H|____   _____   _____   _____   ____
 * 50%       |   |   |   |   |   |   |   |   |
 *          L|   -----   -----   -----   -----
 *           |
 * LED .5Hz H|________       _________       ____
 * 50%       |       |       |       |       |
 *          L|       ---------       ---------
 *           +---|---|---|---|---|---|---|---|--->
 *              0.5  1  1.5  2  2.5  3  3.5  4  (time in seconds)
 *
 * The upper signal is a square waveform with 1Hz 50% duty cycle. The
 * lower one is a square waveform with 0.5Hz, 50% duty cycle. These are
 * the 2 modes in which i need to flash the LEDs. So if i configure a
 * single timer with 0.5sec period, that can help me drive both LEDs.
 *
 * Conclusion: I'm configuring a timer to 2Hz
 */
static void Tim2Hz_Config_IT(void) {
    /**
     * LED 1Hz  H|____   _____   _____   _____   ____
     * 50%       |   |   |   |   |   |   |   |   |
     *          L|   -----   -----   -----   -----
     *           |
     * LED .5Hz H|________       _________       ____
     * 50%       |       |       |       |       |
     *          L|       ---------       ---------
     *           +---|---|---|---|---|---|---|---|--->
     *              0.5  1  1.5  2  2.5  3  3.5  4  (time in seconds)
     *
     * The upper signal is a square waveform with 1Hz 50% duty cycle. The
     * lower one is a square waveform with 0.5Hz, 50% duty cycle. These are
     * the 2 modes in which i need to flash the LEDs. So if i configure a
     * single timer with 0.5sec period, that can help me drive both LEDs.
     *
     * Conclusion: I'm configuring a timer to 2Hz
     */

    // TIM2's bus clock is: 108MHz, so 108 000 000 = 2*(Period+1)*(Prescaler+1)
    Tim2HzHandle.Instance = TIMER_2HZ;
    Tim2HzHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    Tim2HzHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    Tim2HzHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
    Tim2HzHandle.Init.Period = 9999;
    Tim2HzHandle.Init.Prescaler = 5399;

    HAL_TIM_Base_Init(&Tim2HzHandle);
    HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

/**
 * UART as usual
 */
static void UART_Config(void) {
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &UartHandle);
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

/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
    /* Place your implementation of fputc here */
    /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
    HAL_UART_Transmit(&UartHandle, (uint8_t *) &ch, 1, 0xFFFF);

    return ch;
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
