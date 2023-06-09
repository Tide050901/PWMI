#include "Sys.h"
#include "WeiDai.h"

void RCC_HSE_Configuration(void)
{
	ErrorStatus HSEStartup;
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);               //使能外部晶振
	HSEStartup=RCC_WaitForHSEStartUp();
	if(HSEStartup==SUCCESS)
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1); //AHB系统时钟
		RCC_PCLK1Config(RCC_HCLK_Div2);   //APB1
		RCC_PCLK2Config(RCC_HCLK_Div1);    //APB2
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);  //设置时钟系统以及分屏  PLLCLK = 8Mhz*9 = 72Mhz;
		RCC_PLLCmd(ENABLE);
		while(RCC_GetFlagStatus(RCC_FLAG_HSERDY)==RESET)
		{
			
		}
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource() != 0x08)
		{
		
		}
	}
	else{
	
	
	}
	
}
