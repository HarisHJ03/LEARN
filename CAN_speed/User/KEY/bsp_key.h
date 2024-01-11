#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "stm32f10x.h"

#define KEY1_GPIO_CLK  RCC_APB2Periph_GPIOB
#define KEY1_GPIO_PORT GPIOB
#define KEY1_GPIO_PIN  GPIO_Pin_1

#define KEY2_GPIO_CLK RCC_APB2Periph_GPIOB
#define KEY2_GPIO_PORT GPIOB
#define KEY2_GPIO_PIN GPIO_Pin_11

#define KEY_ON  0
#define KEY1_ON 1
#define KEY2_ON 2


void KEY_GPIO_Config(void);
uint8_t Key_GetNum(void);

#endif
