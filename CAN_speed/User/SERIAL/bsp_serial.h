#ifndef __BSP_SERIAL_H
#define __BSP_SERIAL_H

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void Serial_Init(void);
void Serial_SendNum(uint16_t Num);
void Serial_SendArray(uint8_t *Array, uint16_t length);
void Serial_SendString(char *String);
#endif
