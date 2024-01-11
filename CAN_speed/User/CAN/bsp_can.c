#include "bsp_can.h"
CanTxMsg TxMessage;

uint8_t GetArray[8];

void MyCAN_Init(void)
{
    RCC_APB2PeriphClockCmd(CAN_GPIO_CLK,ENABLE);
    RCC_APB1PeriphClockCmd(CAN_CLK,ENABLE);    
    
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin=CAN_TX_PIN;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(CAN_GPIO,&GPIO_InitStructure);
	
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin=CAN_RX_PIN;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
    GPIO_Init(CAN_GPIO,&GPIO_InitStructure);

    CAN_InitTypeDef CAN_InitStructure;
    CAN_InitStructure.CAN_ABOM=DISABLE;
    CAN_InitStructure.CAN_AWUM=DISABLE;
    CAN_InitStructure.CAN_BS1=CAN_BS1_5tq;
    CAN_InitStructure.CAN_BS2=CAN_BS2_3tq;
    CAN_InitStructure.CAN_Mode=CAN_Mode_Normal;
    CAN_InitStructure.CAN_NART=DISABLE;
    CAN_InitStructure.CAN_Prescaler=4;
    CAN_InitStructure.CAN_RFLM=DISABLE;
    CAN_InitStructure.CAN_SJW=CAN_SJW_2tq;
    CAN_InitStructure.CAN_TTCM=DISABLE;
    CAN_InitStructure.CAN_TXFP=DISABLE;
    CAN_Init(CANx,&CAN_InitStructure);

}
void MyCAN_FilterInit(void)
{
    CAN_FilterInitTypeDef CAN_FilterInitStructure;
    CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;
    CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;
    CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;
    CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;
    CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
    CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;
    CAN_FilterInitStructure.CAN_FilterNumber=0;
    CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;
    CAN_FilterInit(&CAN_FilterInitStructure);
}
void CAN_NVICConfig(void)
{
    CAN_ITConfig(CANx,CAN_IT_FMP0,ENABLE);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 	1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

}

void CAN1_SendMsg(uint8_t* data, uint8_t len, uint32_t id)
{

	TxMessage.StdId = 0x200;	// 标准标识符
	TxMessage.IDE = CAN_Id_Standard;
	TxMessage.RTR = CAN_RTR_Data;
	TxMessage.DLC = 0x08; // 数据长度
	for (uint8_t i = 0; i < len; i++)
		TxMessage.Data[i] = data[i]; // 数据
	CAN_Transmit(CAN1, &TxMessage);
}

void CAN_Config(void)
{
    MyCAN_Init();
    MyCAN_FilterInit();
    MyCAN_FilterInit();
    CAN_NVICConfig();
}

void CAN1_GetMsg(CanRxMsg *RxMessage)
{
    RxMessage->StdId = 0x201;
    RxMessage->ExtId = 0x00;
    RxMessage->DLC = 0;
    RxMessage->IDE = CAN_Id_Standard;
    RxMessage->FMI = 0;
    RxMessage->RTR = CAN_RTR_Data;
    for (uint8_t i = 0; i < 8; i++)
    {
        GetArray[i] = RxMessage->Data[i];
    }
}
