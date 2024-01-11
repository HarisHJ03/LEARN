#include "bsp_key.h"
#include "Delay.h"
#include "bsp_led.h"

void KEY_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK, ENABLE);

  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStruct.GPIO_Pin = KEY1_GPIO_PIN|KEY2_GPIO_PIN;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStruct);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == KEY_ON)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1) == KEY_ON);
		Delay_ms(20);
		KeyNum = KEY1_ON;
	}	
	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == KEY_ON)
		{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == KEY_ON);
		Delay_ms(20);
		KeyNum = KEY2_ON;
	}
	return KeyNum;
}
