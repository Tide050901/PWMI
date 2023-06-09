#include "stm32f10x.h"                  // Device header
#include "delay.h"

/**
   * @brief		按键初始化，调用GPIOB寄存器，并设定端口B4和B6
   * @param		无
   * @retval	无
   */
void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}
/**
   * @brief		读取按钮的状态
   * @param		无
   * @retval	KeyNum
   */
uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)==0);
		Delay_ms(20);
		KeyNum = 6;
	}
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)==0);
		Delay_ms(20);
		KeyNum = 4;
	}
	
	return KeyNum;
}
