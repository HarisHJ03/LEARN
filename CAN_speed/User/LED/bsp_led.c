#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	/* 定义一个 GPIO_InitTypeDef 的结构体 */
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* 开启外设时钟 */
	RCC_APB2PeriphClockCmd(LED1_GPIO_CLK|LED2_GPIO_CLK|LED3_GPIO_CLK, ENABLE);

	/* 选择要控制的 GPIO 引脚 */
	GPIO_InitStruct.GPIO_Pin   = LED1_GPIO_PIN|LED2_GPIO_PIN|LED3_GPIO_PIN;
	/* 选择引脚模式为通用推完输出 */
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	/* 设置引脚速度的为 50Hz */
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	/* 调用库函数，初始化GPIO */
	GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);

	GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
	GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);
	GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}

void LED_Turn(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	//如果关灯则开灯，反之亦然
	if (GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin) == LED_OFF)
	{
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}
	else
	{
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}
}

void LED_Turn_ON(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_ResetBits(GPIOx, GPIO_Pin);
}
void LED_Turn_OFF(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_SetBits(GPIOx, GPIO_Pin);
}
