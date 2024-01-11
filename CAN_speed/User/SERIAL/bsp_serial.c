#include "bsp_serial.h"

void Serial_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    USART_InitTypeDef USART_InitStructrue;
    USART_InitStructrue.USART_BaudRate = 9600;
    USART_InitStructrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructrue.USART_Mode = USART_Mode_Tx;
    USART_InitStructrue.USART_Parity = USART_Parity_No;
    USART_InitStructrue.USART_StopBits = USART_StopBits_1;
    USART_InitStructrue.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStructrue);
    USART_Cmd(USART1, ENABLE);
}
void Serial_SendNum(uint16_t Num)
{
    USART_SendData(USART1, Num);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
        ;
}
void Serial_SendArray(uint8_t *Array, uint16_t length)
{
    uint16_t i;
    for (i = 0; i < length; i++)
    {
        USART_SendData(USART1, Array[i]);
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
            ;
    }
}
void Serial_SendString(char *String)
{
    uint8_t i;
    for (i = 0; String[i] != 0; i++)
    {
        USART_SendData(USART1, String[i]);
        while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
            ;
    }
}
