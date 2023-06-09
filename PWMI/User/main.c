#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "PWMI.h"
#include "WeiDai.h"
#include "OLED.h"
#include "CountSensor.h"
int main()
{
	CountSensor_Init();

	OLED_Init();
	My_PWMI_Init();
	OLED_ShowString(1,1,"Freq=");
	OLED_ShowNum(1,6,IC_GetFreq(),6);
	while(1)
	{
		
	}
	
	
}
