#ifndef __PWMO_H_
#define __PWMO_H_

#include "WeiDai.h"
#include "stm32f10x.h" 
void My_PWMO_Init(void);
void Set_My_Compare1(uint16_t My_Compare);
void Set_My_Prescaler(uint16_t My_Prescaler);
#endif
