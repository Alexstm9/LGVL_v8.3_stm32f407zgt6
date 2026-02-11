/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.h"
#include "fsmc.h"
#include "gpio.h"
#include "tim.h"
#include "usart.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include "math.h"
#include "stdio.h"
#include "sys.h"
#include "touch.h"

#include "delay.h"
// #include "led.h"
// #include "key.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lvgl.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Error_Handler(void);
extern void MX_FSMC_Init(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick.
   */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_FSMC_Init();
  MX_TIM7_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  /* 初始化按键 */

  lcd_init();    /* 初始化LCD */
  tp_dev.init(); /* 初始化触摸屏 */

  // 添加一个测试串口输出的语句
  printf("System initialized successfully!\r\n");

  // 检查校准参数是否有效
  if ((tp_dev.xfac != tp_dev.xfac || tp_dev.yfac != tp_dev.yfac) || // 检查NaN
      (tp_dev.xfac == 0 || tp_dev.yfac == 0) ||                     // 检查零值
      (tp_dev.xc < 0 || tp_dev.yc < 0)) { // 检查无效值
    printf("Error: Invalid calibration parameters! Please calibrate touch "
           "panel.\r\n");
  } else {
    printf("Touch panel calibration parameters are valid.\r\n");
  }

  HAL_TIM_Base_Start_IT(&htim7); /* 定时器初始化必须在LVGL初始化前完成 */
  lv_init();                     /* LVGL初始化 */
  lv_port_disp_init();           /* 显示端口初始化 */
  lv_port_indev_init();          /* 输入设备端口初始化 */

  // 创建LVGL界面元素
  lv_obj_t *switch_obj = lv_switch_create(lv_scr_act());
  lv_obj_set_size(switch_obj, 120, 60);
  lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);

  // 创建一个标签用于显示触摸坐标
  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "Touch screen to test");
  lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -10);

  printf("LVGL initialized and UI elements created.\r\n"); // 确认LVGL初始化

  uint16_t last_x = 0, last_y = 0;
  uint8_t last_state = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) {
    // 测试触摸屏直接读取
    tp_dev.scan(0); // 扫描触摸屏

    if ((tp_dev.sta & TP_PRES_DOWN) && !(last_state & TP_PRES_DOWN)) {
      // 触摸按下
      printf("Touch pressed at: x=%d, y=%d (logical: %d, %d)\r\n", tp_dev.x[0],
             tp_dev.y[0], tp_dev.x[0], tp_dev.y[0]);
      last_x = tp_dev.x[0];
      last_y = tp_dev.y[0];
      last_state = tp_dev.sta;

      // 更新标签显示坐标
      char buf[60];
      sprintf(buf, "Pressed: (%d, %d)", tp_dev.x[0], tp_dev.y[0]);
      lv_label_set_text(label, buf);
    } else if (!(tp_dev.sta & TP_PRES_DOWN) && (last_state & TP_PRES_DOWN)) {
      // 触摸释放
      printf("Touch released at: x=%d, y=%d\r\n", tp_dev.x[0], tp_dev.y[0]);
      last_state = tp_dev.sta;
    }

    delay_ms(5);
    lv_timer_handler(); /* LVGL定时器处理 */
  }
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1) {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line) {
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line
     number, ex: printf("Wrong parameters value: file %s on line %d\r\n", file,
     line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
