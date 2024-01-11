#ifndef __BSP_TIM_H
#define __BSP_TIM_H

#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_exti.h"

void TIM_Init(void);
uint16_t Return_Sec(void);
uint16_t Return_Capturel(void);
#endif
