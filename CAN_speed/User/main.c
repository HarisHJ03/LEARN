#include "stm32f10x.h"
#include "bsp_key.h"
#include "Delay.h"
#include "OLED.h"
#include "bsp_can.h"
#include "bsp_pid.h"


CanRxMsg RxMessage;
uint8_t CAN_FLAG = 0;
extern uint8_t GetArray[8];
int16_t get;
int16_t out;
uint8_t data[8] = {0x03, 0xE8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
int main(void)
{
	OLED_Init();
	CAN_Config();
	OLED_ShowString(1, 1, "speed:");
	while (1)
	{
		if (1)
		{
			CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
			get = ((int32_t)RxMessage.Data[0] << 8) | (int32_t)RxMessage.Data[1];
			
			out =pid_cla(0,0,0,2000,get);
			CAN1_SendMsg(data, 0x08, 0x200);
			OLED_ShowHexNum(1,7,get,4);
			OLED_ShowHexNum(1, 7, out, 4);
		}
	}
}
void CAN_RX1_IRQHandler(void)
{
	if (CAN_GetITStatus(CAN1, CAN_IT_FMP0) != RESET)
	{
		CAN_FLAG = 1;
		CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
	}
	CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);
}
