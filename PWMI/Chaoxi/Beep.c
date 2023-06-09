#include "Beep.h"
u16 PWM;
void Beep_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //ÍÆÍìÊä³ö
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	//50MHz
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}
void Beep_500Hz()
{	
	BPB_OUT(5) = 0;
	Delay_us((2000*PWM)/100);
	BPB_OUT(5) = 1;
	Delay_us(2000-((2000*PWM)/100));
}
void Beep_2_5KHz()
{
	BPB_OUT(5) = 0;
	Delay_us((500*PWM)/100);
	BPB_OUT(5) = 1;
	Delay_us(500-((500*PWM)/100));
}
void Beep_3_3KHz()
{
	BPB_OUT(5) = 0;
	Delay_us((300*PWM)/100);
	BPB_OUT(5) = 1;
	Delay_us(300-((300*PWM)/100));
}
void Beep_10KHz()
{
	BPB_OUT(5) = 0;
	Delay_us((100*PWM)/100);
	BPB_OUT(5) = 1;
	Delay_us(100-((100*PWM)/100));
}


