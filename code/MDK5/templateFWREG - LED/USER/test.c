#include "sys.h"
#include "stm32f10x.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	Stm32_Clock_Init(9);//72M
	delay_init(72);
	LED_Init();
	while (1)
	{
		GPIOA->ODR &= ~(1U << 8);//PA8 Port output data:Low
		GPIOD->ODR |=  (1U << 2);//PD2 Port output data:High
		delay_ms(500);
		GPIOA->ODR |=  (1U << 8);//PA8 Port output data:High
		GPIOD->ODR &= ~(1U << 2);//PD2 Port output data:Low
		delay_ms(500);
	}
	
}
