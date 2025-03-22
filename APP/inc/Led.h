/**
  ************************ Copyright *************** 
  *           (C) Copyright 2025,txt1994,China.
  *                  All Rights Reserved
  *
  *                 https://github.com/MAX-GitHub-Z/MCU_BootLoader
  *                 email:3014759318@qq.com
  *                 QQ   :3014759318
  *      
  * FileName     : Led.h   
  * Version      : v1.0     
  * Author       : MAX-GitHub-Z         
  * Date         : 2025-03-22         
  * Description  :    
  * Function List:  
  * Toolchain : RealView Development Suite
  *             RealView Microcontroller Development Kit (MDK)
  *             ARM Developer Suite (ADS)
  *             Keil uVision
  ******************************************************
**/

#ifndef __LED_H_
#define __LED_H_

/* FreeRTOS头文件 */
#include "FreeRTOS.h"
#include "task.h"
/* 开发板硬件bsp头文件 */
#include "stm32f10x.h"
#include <stdio.h>

/* 定义LED连接的GPIO端口, 用户只需要修改下面的代码即可改变控制的LED引脚 */
// R-红色
#define LED_GPIO_PORT    		GPIOC			              /* GPIO端口 */
#define LED_GPIO_CLK 	    	RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define LED_GPIO_PIN				GPIO_Pin_13			        /* 连接到SCL时钟线的GPIO */



/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* 使用标准的固件库控制IO*/
#define LED(a)	if (a)	\
					GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN)



/*************************************
  * @Name   : LedTaskCreate
	* @brief  : Led灯的任务初始化
  * @param  : None
  * @retval ：None
  * @author : MAX-GitHub-Z 
  * @Data   : 2025-03-22
  * <description> :
 ****************************************/
void LedTaskCreate(void);

#endif

