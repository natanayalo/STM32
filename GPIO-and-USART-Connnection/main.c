#include <stdint.h>
#include <Defines.h>

uint32_t send_one = 0,send_zero = 0;

void config_all() {

	//RCC CONFIGURATION
	uint32_t* adressRCC_APB = (uint32_t*)(RCC + RCC_APB2ENR);
	*adressRCC_APB = *adressRCC_APB | USART1_ENABLE;
	*adressRCC_APB = *adressRCC_APB | IO_PC_ENABLE;
	*adressRCC_APB = *adressRCC_APB | IO_PA_ENABLE;

	//USART SENDING CONFIGURATION
	uint32_t* adressCR1 = (uint32_t*)(USART1 + USART_CR1);
	uint32_t* adressMant = (uint32_t*)(USART1 + USART_BRR);
	*adressCR1 = *adressCR1 | USART_CR1_UE;
	*adressCR1 = *adressCR1 | USART_CR1_Mbit;
	*adressMant = mant;

	//CONFIGURE PORT C GPIO
	uint32_t* adressGPIOC_CRL = (uint32_t*)(GPIOC + GPIOx_CRL);
	uint32_t* adressGPIOC_ODR = (uint32_t*)(GPIOC + GPIOx_ODR);
	*adressGPIOC_CRL = *adressGPIOC_CRL & CRL_PUSH_PULL_AND;
	*adressGPIOC_CRL = *adressGPIOC_CRL | CRL_PUSH_PULL_OR;
	*adressGPIOC_ODR = *adressGPIOC_ODR | ODR_PUSH_PULL_OR;

	//CONFIGURE PORT A GPIO
	uint32_t* adressGPIOA_CRH = (uint32_t*)(GPIOA + GPIOx_CRH);
	*adressGPIOA_CRH = *adressGPIOA_CRH | CRH_MODE9;
	*adressGPIOA_CRH = *adressGPIOA_CRH | CRH_MODE10;
	*adressGPIOA_CRH = *adressGPIOA_CRH & CRH_CNF9_10_AND;
	*adressGPIOA_CRH = *adressGPIOA_CRH | CRH_CNF9_10_OR;

	//TRANSFER ENABLE
	*adressCR1 = *adressCR1 | USART_CR1_TE;
	*adressCR1 = *adressCR1 | USART_CR1_RE;

}

int main(void)
{
	config_all(); //CONFIGURATIONS
	uint32_t* adressDR = (uint32_t*)(USART1 + USART_DR);
	uint32_t* adressGPIOC_CRH = (uint32_t*)(GPIOC + GPIOx_CRH);
	
 
	while (1)
	{
		if (send_one)
		{
			*adressDR = TURNON;
			send_one = 0;
		}
		else if (send_zero)
		{
			*adressDR = TURNOFF;
			send_zero = 0;
		}

		uint32_t temp_dr,old_dr;
		temp_dr = *adressDR;
		if(temp_dr != old_dr){
			old_dr = temp_dr;
			if (temp_dr == 0x31)
			{
				//TURN ON LED
				*adressGPIOC_CRH = *adressGPIOC_CRH | MODE13;
			}
			else if (temp_dr == 0x30)
				{
				//TURN OFF LED
				*adressGPIOC_CRH = *adressGPIOC_CRH & MODE13_OFF;
			}
		}
	}
}
