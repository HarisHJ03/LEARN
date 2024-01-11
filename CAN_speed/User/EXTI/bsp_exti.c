#include "bsp_exti.h"


static void EXTI_NVIC_Config(void) // 加static表示只能在EXTI_Key_Config里面调用
{
  NVIC_InitTypeDef NVIC_InitStrucy;
  // 配置优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  //配置中断源
	NVIC_InitStrucy.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
  //配置抢占优先级
  NVIC_InitStrucy.NVIC_IRQChannelSubPriority = 1;
  //配置子优先级
  NVIC_InitStrucy.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStrucy.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStrucy);

}

void EXTI_Key_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  EXTI_InitTypeDef EXTI_InitStruct;
  /*配置中断优先级*/
  EXTI_NVIC_Config();
  /*开时钟*/
  RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK, ENABLE);
  RCC_APB2PeriphClockCmd(KEY1_INT_EXTI_CLK, ENABLE);
  /* 初试化 GPIO */
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_InitStruct.GPIO_Pin = KEY1_INT_GPIO_PIN;
  GPIO_InitStruct.GPIO_Speed = KEY1_INT_GPIO_SPEED;
  GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStruct);

  GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE);
  
  EXTI_InitStruct.EXTI_Line = KEY1_INT_EXTI_LINE;
  EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStruct.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStruct);
}


uint16_t GET_Config(void)
{
  return 0;
}
