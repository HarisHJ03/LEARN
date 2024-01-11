#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

/* RED */
#define LED1_GPIO_PORT	GPIOA
#define LED1_GPIO_CLK		RCC_APB2Periph_GPIOA
#define LED1_GPIO_PIN 	GPIO_Pin_0

/* GREEN */
#define LED2_GPIO_PORT	GPIOA
#define LED2_GPIO_CLK		RCC_APB2Periph_GPIOA
#define LED2_GPIO_PIN 	GPIO_Pin_1

/* BLUE */
#define LED3_GPIO_PORT	GPIOA
#define LED3_GPIO_CLK		RCC_APB2Periph_GPIOA
#define LED3_GPIO_PIN 	GPIO_Pin_2

#define LED_ON  1
#define LED_OFF 0

void LED_GPIO_Config(void);
void LED_Turn_ON(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void LED_Turn_OFF(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void LED_Turn(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif
