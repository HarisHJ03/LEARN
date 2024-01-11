#ifndef __BSP_CAN_H
#define __BSP_CAN_H

#include "stm32f10x.h"
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "bsp_serial.h"
#include "misc.h"

extern uint8_t GetArray[8];

#define CANx CAN1
#define CAN_GPIO_CLK RCC_APB2Periph_GPIOA
#define CAN_CLK RCC_APB1Periph_CAN1
#define CAN_TX_PIN GPIO_Pin_12
#define CAN_RX_PIN GPIO_Pin_11
#define CAN_GPIO GPIOA

void MyCAN_Init(void);
void MyCAN_FilterInit(void);
void CAN_NVICConfig(void);
void CAN1_SendMsg(uint8_t *data, uint8_t len, uint32_t id);
void CAN_Config(void);
void CAN1_GetMsg(CanRxMsg *RxMessage);

#endif
