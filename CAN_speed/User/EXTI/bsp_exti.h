#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "stm32f10x.h"
#include "stm32f10x_exti.h"

#define KEY1_INT_GPIO_CLK        RCC_APB2Periph_GPIOB
#define KEY1_INT_GPIO_PORT       GPIOB
#define KEY1_INT_GPIO_PIN        GPIO_Pin_1
#define KEY1_INT_GPIO_SPEED      GPIO_Speed_50MHz

#define KEY1_INT_EXTI_CLK        RCC_APB2Periph_AFIO
#define KEY1_INT_EXTI_PORTSOURCE GPIO_PortSourceGPIOB
#define KEY1_INT_EXTI_PINSOURCE  GPIO_PinSource1
#define KEY1_INT_EXTI_LINE       EXTI_Line1
#define KEY1_INT_EXTI_IRQ        EXTI1_IRQn

#define KEY1_IQRHandler          EXTI1_IRQHandler()

void EXTI_Key_Config(void);
uint16_t GET_Config(void);
#endif 
