//Defines:

//Gpio ports:
#define GPIOA								0x40010800
#define GPIOB								0x40010C00
#define GPIOC								0x40011000

//Gpio Offset:
#define	GPIOx_CRL						0x00
#define	GPIOx_CRH						0x04
#define	GPIOx_IDR						0x08
#define	GPIOx_ODR						0x0C

//GPIO MASKING
//PORT C
#define	CRL_PULL_DOWN_AND		0xFFFFFF40
#define	CRL_PULL_DOWN_OR		0x40
#define	ODR_PULL_DOWN_OR		0x01
#define	ODR_PUSH_PULL_OR		0x01
#define	CRL_PUSH_PULL_AND		0xFFFFFF11
#define	CRL_PUSH_PULL_OR		0x11

//PORT A
#define	CRL_PULL_DOWN_AND		0xFFFFFF40
#define	CRL_PULL_DOWN_OR		0x40
#define	ODR_PULL_DOWN_OR		0x01
#define	ODR_PUSH_PULL_OR		0x01
#define	CRL_PUSH_PULL_OR		0x11
#define	CRH_MODE9						0x10
#define	CRH_MODE10					0x100
#define	CRH_CNF9_10_AND			0xFFFFF33F
#define	CRH_CNF9_10_OR			0x880


#define	CRC	    						0x40023000
#define	DMA1	  						0x40020000
#define	MODE13							0x100000
#define	MODE13_OFF					0xFFCFFFFF
#define	USART1  						0x040013800
#define	AFIO    						0x0400103FF
#define	RCC    							0x40021000 			//RCC - Reset And Clock Control

//USART Offsets
#define	USART_SR						0x00
#define	USART_DR						0x04
#define	USART_BRR						0x08
#define	USART_CR1						0x0C
#define	USART_CR2						0x10
#define	USART_CR3						0x14
#define	USART_GTPR					0x18
  
//USART	MASKING
#define	USART_CR1_UE						0x2000
#define	USART_CR1_Mbit					0x1000
#define	USART_CR2_StopBits			0x2000
#define	USART_CR3_DMAT					0x80
#define	USART_CR1_RE						0x4
#define	USART_CR3_DMAR					0x40
#define	USART_BRR_Mantissa			0xFFF0
#define	USART_BRR_Fraction			0xF
#define	USART_CR1_TE						0x8
#define	USART_CR1_TE_OFF				0xFFFFFFF7
#define	USART_DR_DR							0x1FF 	//THATS CLEAR THE TXE BIT IN USART_SR
#define	USART_SR_TC							0x40		//WHEN TC = 1 THE TRANSMISSION OF THE LAST FRAME IS COMPLETED
#define	USART_SR_RXNE						0x20
#define frac										0xC
#define mant										0x1D4C

//RCC OFFSETS
#define RCC_APB2ENR 				0x18
#define RCC_CFGR 						0x04

//RCC MASKING
#define USART1_ENABLE 			0x4000
#define IO_TIM1_ENABLE  		0x800
#define IO_PC_ENABLE  			0x10
#define IO_PA_ENABLE  			0x4
#define IO_AFIO_ENABLE  		0x01
#define PLL_READY_AND_ON  	0x3000000
#define MCO_PLL_MODE		  	0x7000000
#define HSI_READY_AND_ON  	0x03

//SWITCH LED
#define TURNOFF  						0x30
#define TURNON  						0x31
