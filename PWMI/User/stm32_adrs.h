#ifndef _STM32_ADRS__H_
#define _STM32_ADRS__H_

#define GPIOC_CRL 	 	 *(unsigned int*)(GPIOC_BASE+0x00)
#define GPIOC_CRH 	 	 *(unsigned int*)(GPIOC_BASE+0x04)
#define GPIOC_IDR 	 	 *(unsigned int*)(GPIOC_BASE+0x08)
#define GPIOC_ODR 	 	 *(unsigned int*)(GPIOC_BASE+0x0C)
#define GPIOC_BSRR 	 	 *(unsigned int*)(GPIOC_BASE+0x10)
#define GPIOC_BRR 	 	 *(unsigned int*)(GPIOC_BASE+0x14)
#define GPIOC_LCKR 	 	 *(unsigned int*)(GPIOC_BASE+0x18)
	
#endif
