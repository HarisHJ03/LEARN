#include "bsp_tim.h"

extern uint16_t second;

void TIM_Init(void)
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//TIM_InternalClockConfig(TIM2);//选择内部时钟
	TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x0F);//选择外部时钟
	
	TIM_TimeBaseInitTypeDef TIM_InitStruct;
	TIM_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//采样频率
	TIM_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;//计数器计数模式
	TIM_InitStruct.TIM_Period = 10-1;//ARR自动重装载器的值
	TIM_InitStruct.TIM_Prescaler = 1-1;//PSC预分频器的值
	TIM_InitStruct.TIM_RepetitionCounter = 0;//重复计时器的值 （高级定时器才有
	TIM_TimeBaseInit(TIM2, &TIM_InitStruct);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//不写的话，初始化后同时进行中断
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);// 使能中断输出信号

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);

	TIM_Cmd(TIM2, ENABLE); // 使能计数器
}
uint16_t Return_Sec(void)
{
	return second;
}

uint16_t Return_Capturel(void)
{
	return TIM_GetCounter(TIM2);
}
