#include "bsp_rccclkconfig.h"

void HSE_SetSysClk( uint32_t RCC_PLLMul_x )
{
	ErrorStatus HSEStatus;
	
   RCC_DeInit();
	
    // 使能 HSE
    RCC_HSEConfig(RCC_HSE_ON);
    //等待
    HSEStatus = RCC_WaitForHSEStartUp();

    if (HSEStatus == SUCCESS){
        FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
        FLASH_SetLatency(FLASH_Latency_2);

        RCC_HCLKConfig(RCC_SYSCLK_Div1);
        RCC_PCLK1Config(RCC_HCLK_Div2);
        RCC_PCLK2Config(RCC_HCLK_Div1);

        RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
        RCC_PLLCmd(ENABLE);
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
        
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
        while (RCC_GetSYSCLKSource() != 0x08)
        ;
    }
    else{

    }
}

void MCO_GPIOConfig(void)//示波器检查频率
{
    /* 定义一个 GPIO_InitTypeDef 的结构体 */
    GPIO_InitTypeDef GPIO_InitStruct;

    /* 开启外设时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* 选择要控制的 GPIO 引脚 */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
    /* 选择引脚模式为通用推完输出 */
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    /* 设置引脚速度的为 50Hz */
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    /* 调用库函数，初始化GPIO */
    GPIO_Init(GPIOB, &GPIO_InitStruct);
}
