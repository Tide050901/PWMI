#include "CountSensor.h"      
#include "LED.h"
uint16_t UP,DOWN,LEFT,RIGHT;
void CountSensor_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//下拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStructure);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2|GPIO_PinSource3|GPIO_PinSource4);
	EXTI_InitStructure.EXTI_Line = EXTI_Line2|EXTI_Line3|EXTI_Line4;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
}


void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1)
		{
			LED(13,0);
		}
		EXTI_ClearITPendingBit(EXTI_Line0);//清除中断悬挂
	}
	
}
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0)
		{
			LED(13,1);
		}
		EXTI_ClearITPendingBit(EXTI_Line2);//清除中断悬挂
	}
	
}
void EXTI3_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line3) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 0)
		{
			LED(14,0);
		}
		EXTI_ClearITPendingBit(EXTI_Line3);//清除中断悬挂
	}
	
}
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_4) == 0)
		{
			LED(14,1);
		}
		EXTI_ClearITPendingBit(EXTI_Line4);//清除中断悬挂
	}
	
}







