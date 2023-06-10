#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "WeiDai.h"
#include "OLED.h"
#include "PWMO.h"
#include "PWMI.h"
int main()
{
	OLED_Init();
	My_PWMI_Init();
	My_PWMO_Init();
	OLED_ShowString(1,1,"Freq=000000Hz");
	OLED_ShowString(2,1,"Compare=00%");
	Set_My_Compare1(90);
	Set_My_Prescaler(720 - 1);
	while(1)
	{
		OLED_ShowNum(1,6,IC_GetFreq(),6);
		OLED_ShowNum(2,9,IC_Get_MyCompare(),2);
	}
	
	
}
