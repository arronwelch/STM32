
#include "sys.h"
#include "led.h"
//init PA6 and PD2 set to output mode,and enale pin clock
//LED IO init
void LED_Init(void)
{
    RCC->APB2ENR |= 1 << 2;//enable PORTA clock
    RCC->APB2ENR |= 1 << 5;//enable PORTD clock
    GPIOA->CRH &= 0XFFFFFFF0;//clear
    GPIOA->CRH |= 0X00000003;//PA8 push-pull output mode
    GPIOA->ODR |= 1<<8;//PA8 output high
    GPIOD->CRL &= 0XFFFFF0FF;//clear
    GPIOD->CRL |= 0X00000300;//PD2 push-pull output mode
    GPIOD->ODR |= 1<<2;//Pd2 output high
}
