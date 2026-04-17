/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "gpio.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LED_TOGGLE_PERIOD       100  // 100ms (0.1秒)
#define USART_BUFFER_SIZE       64
#define HELLO_WORLD_INTERVAL    500  // 500ms发送一次hello world
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
volatile uint8_t led_state = 0;

/* USER CODE END Variables */
/* Definitions for LCDTask */
osThreadId_t LCDTaskHandle;
const osThreadAttr_t LCDTask_attributes = {
  .name = "LCDTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for USARTTask */
osThreadId_t USARTTaskHandle;
const osThreadAttr_t USARTTask_attributes = {
  .name = "USARTTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};
/* Definitions for myMutex01 */
osMutexId_t myMutex01Handle;
const osMutexAttr_t myMutex01_attributes = {
  .name = "myMutex01"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartLCDTask(void *argument);
void StartUSARTTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
  
  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* creation of myMutex01 */
  myMutex01Handle = osMutexNew(&myMutex01_attributes);

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LCDTask */
  LCDTaskHandle = osThreadNew(StartLCDTask, NULL, &LCDTask_attributes);

  /* creation of USARTTask */
  USARTTaskHandle = osThreadNew(StartUSARTTask, NULL, &USARTTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartLCDTask */
/**
  * @brief  Function implementing the LCDTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartLCDTask */
void StartLCDTask(void *argument)
{
  /* USER CODE BEGIN StartLCDTask */
  uint32_t last_toggle_time = 0;
  uint32_t current_time = 0;

  // 使用互斥锁保护UART访问
  if (osMutexAcquire(myMutex01Handle, osWaitForever) == osOK) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"LED Control Task Started\r\n", 26, HAL_MAX_DELAY);
    osMutexRelease(myMutex01Handle);
  }

  /* Infinite loop */
  for(;;)
  {
    current_time = HAL_GetTick();

    // 0.1秒自动闪烁
    if (current_time - last_toggle_time >= LED_TOGGLE_PERIOD) {
      HAL_GPIO_TogglePin(LED_PIN_GPIO_Port, LED_PIN_Pin);
      led_state = !led_state;
      last_toggle_time = current_time;
      
      // 安全的UART打印
      if (osMutexAcquire(myMutex01Handle, osWaitForever) == osOK) {
        char msg[30];
        snprintf(msg, sizeof(msg), "LED Toggled - State: %d\r\n", led_state);
        HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
        osMutexRelease(myMutex01Handle);
      }
    }

    osDelay(10); // 10ms延迟，降低CPU占用
  }
  /* USER CODE END StartLCDTask */
}

/* USER CODE BEGIN Header_StartUSARTTask */
/**
* @brief Function implementing the USARTTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartUSARTTask */
void StartUSARTTask(void *argument)
{
  /* USER CODE BEGIN StartUSARTTask */
  uint32_t last_hello_time = 0;
  uint32_t current_time = 0;

  // 使用互斥锁保护初始化消息
  if (osMutexAcquire(myMutex01Handle, osWaitForever) == osOK) {
    HAL_UART_Transmit(&huart1, (uint8_t*)"USART Communication Task Started!\r\n", 35, HAL_MAX_DELAY);
    osMutexRelease(myMutex01Handle);
  }

  /* Infinite loop */
  for(;;)
  {
    current_time = HAL_GetTick();

    // 每500ms发送一次hello world
    if (current_time - last_hello_time >= HELLO_WORLD_INTERVAL) {
      if (osMutexAcquire(myMutex01Handle, osWaitForever) == osOK) {
        HAL_UART_Transmit(&huart1, (uint8_t*)"hello,world!\r\n", 14, HAL_MAX_DELAY);
        osMutexRelease(myMutex01Handle);
      }
      last_hello_time = current_time;
    }

    osDelay(100); // 100ms延迟，平衡性能和响应性
  }
  /* USER CODE END StartUSARTTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

