#include "LED.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	//50MHz
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}
/**
   * @brief		LED显示函数
   * @param		i选择管脚，i = 0-7;
				j选择输出电平：j = 0,输出低电平点亮led，j = 1，输出高电平熄灭led
   * @retval 	无返回值
   */
void LED(unsigned char i,unsigned char j)
{

	BPC_OUT(i) = j;
}

