#include "LED.h"                  // Device header

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 	//50MHz
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}
/**
   * @brief		LED��ʾ����
   * @param		iѡ��ܽţ�i = 0-7;
				jѡ�������ƽ��j = 0,����͵�ƽ����led��j = 1������ߵ�ƽϨ��led
   * @retval 	�޷���ֵ
   */
void LED(unsigned char i,unsigned char j)
{

	BPC_OUT(i) = j;
}

