
// #include "sys.h"
// #include "led.h"
// //init PA6 and PD2 set to output mode,and enale pin clock
// //LED IO init
// void LED_Init(void)
// {
//     RCC->APB2ENR |= 1 << 2;//enable PORTA clock
//     RCC->APB2ENR |= 1 << 5;//enable PORTD clock
//     GPIOA->CRH &= 0XFFFFFFF0;//clear
//     GPIOA->CRH |= 0X00000003;//PA8 general perpose push-pull output mode, max speed 50MHz
//     GPIOA->ODR |= 1<<8;//PA8 output high
//     GPIOD->CRL &= 0XFFFFF0FF;//clear
//     GPIOD->CRL |= 0X00000300;//PD2 general perpose push-pull output mode, max speed 50MHz
//     GPIOD->ODR |= 1<<2;//Pd2 output high
// }

#include "led.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;                  //define GPIO init structure
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //enable GPIOA clock
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE); //enable GPIOD c;ock

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA, GPIO_Pin_8);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_SetBits(GPIOD, GPIO_Pin_2);
}
