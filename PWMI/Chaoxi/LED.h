#ifndef __LED_H_
#define __LED_H_
#include "WeiDai.h"
#include "stm32f10x.h" 

#define LED_PORT    GPIOA 
#define LED_PIN   (GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7)
void LED_Init(void);
void LED(unsigned char i,unsigned char j);

#endif
