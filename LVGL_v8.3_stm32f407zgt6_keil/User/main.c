/**
 ****************************************************************************************************
 * @file        main.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2021-10-25
 * @brief       LVGL移植 实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 探索者 F407开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/LCD/lcd.h"
#include "./BSP/KEY/key.h"
#include "./BSP/TOUCH/touch.h"

#include "./BSP/TIMER/btim.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"

#include "lv_demo_stress.h"  //没有显示很可能是栈不够大
#include "lv_demo_widgets.h"


int main(void)
{
    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(336, 8, 2, 7); /* 设置时钟, 168Mhz */
    delay_init(168);                    /* 延时初始化 */
    usart_init(115200);                 /* 串口初始化为115200 */
    led_init();                         /* 初始化LED */
    key_init();                         /* 初始化按键 */
    
    lcd_init();                         /* 初始化LCD */
    tp_dev.init();                      /* 初始化触摸屏 */
    
//    // 检查校准参数是否有效
//    if((tp_dev.xfac != tp_dev.xfac || tp_dev.yfac != tp_dev.yfac) || // 检查NaN
//       (tp_dev.xfac == 0 || tp_dev.yfac == 0) || // 检查零值
//       (tp_dev.xc < 0 || tp_dev.yc < 0)) { // 检查无效值
//        printf("Error: Invalid calibration parameters! Please calibrate touch panel.\r\n");
//    }

    printf("Peripherals initialized...\r\n");
    
    btim_timx_int_init(1000-1, 84-1);   /* 定时器初始化必须在LVGL初始化前完成 */
    printf("Timer configured...\r\n");
    lv_init();                          /* LVGL初始化 */
    printf("LVGL initialized...\r\n");
    lv_port_disp_init();                /* 显示端口初始化 */
    printf("Display port initialized...\r\n");
    lv_port_indev_init();               /* 输入设备端口初始化 */
    printf("Input device initialized...\r\n");
  
    // // 创建LVGL界面元素
    // lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
    // lv_obj_set_size(switch_obj, 120, 60);
    // lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);

//    // 创建一个标签用于显示触摸坐标
//    lv_obj_t * label = lv_label_create(lv_scr_act());
//    lv_label_set_text(label, "Touch screen to test");
//    lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, -10);
//    
//    uint16_t last_x = 0, last_y = 0;
//    uint8_t last_state = 0;

    
    uint32_t counter = 0;

    lv_demo_stress();
    printf("Demo started...\r\n");

    
    while(1)
    {
//        // 测试触摸屏直接读取
//        tp_dev.scan(0); // 扫描触摸屏
//        
//        if((tp_dev.sta & TP_PRES_DOWN) && !(last_state & TP_PRES_DOWN)) {
//            // 触摸按下
//            printf("Touch pressed at: x=%d, y=%d (logical: %d, %d)\r\n", 
//                   tp_dev.x[0], tp_dev.y[0], tp_dev.x[0], tp_dev.y[0]);
//            last_x = tp_dev.x[0];
//            last_y = tp_dev.y[0];
//            last_state = tp_dev.sta;
//            
//            // 更新标签显示坐标
//            char buf[60];
//            sprintf(buf, "Pressed: (%d, %d)", tp_dev.x[0], tp_dev.y[0]);
//            lv_label_set_text(label, buf);
//        } else if(!(tp_dev.sta & TP_PRES_DOWN) && (last_state & TP_PRES_DOWN)) {
//            // 触摸释放
//            printf("Touch released at: x=%d, y=%d\r\n", tp_dev.x[0], tp_dev.y[0]);
//            last_state = tp_dev.sta;
//        }
        
        lv_timer_handler();
        delay_ms(5);

        // LED快速闪烁指示程序运行
        if(counter++ % 50 == 0) {
            LED1_TOGGLE();
            printf("Tick: %lu\r\n", HAL_GetTick());
        }
    }
}
