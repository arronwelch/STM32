#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
    RCC->APB2ENR |= 1U << 2;//Bit 2 IOPAEN: I/O port A clock enable
    RCC->APB2ENR |= 1U << 5;//Bit 5 IOPDEN: I/O port D clock enable
    GPIOA->CRH &= 0XFFFFFFF0;//clear PA8
    GPIOA->CRH |= 0X00000003;//PA8 00: General purpose output push-pull;11: Output mode, max speed 50 MHz.
    GPIOA->ODR |= 1U << 8;//PA8 Port output data:High
    GPIOD->CRL &= 0XFFFFF0FF;//clear PD2
    GPIOD->CRL |= 0X00000300;//PD2 00: General purpose output push-pull;11: Output mode, max speed 50 MHz.
    GPIOD->ODR |= 1U << 2;//PD2 Port output data:High
}
