#ifndef __Beep_H_
#define __Beep_H_

#include "Delay.h"
#include "stm32f10x.h"                  // Device header
#include "WeiDai.h"
extern u16 PWM;
void Beep_Init(void);
void Beep_500Hz(void);
void Beep_10KHz(void);
void Beep_3_3KHz(void);
void Beep_2_5KHz(void);

#endif
