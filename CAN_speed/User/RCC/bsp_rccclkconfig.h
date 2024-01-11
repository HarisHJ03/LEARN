#ifndef __BSP_RCCCLKCONFIG
#define __BSP_RCCCLKCONFIG

#include "stm32f10x.h"
#include "stm32f10x_flash.h"

void HSE_SetSysClk( uint32_t RCC_PLLMul_x );
void MCO_GPIOConfig(void);

#endif
