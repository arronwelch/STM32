#include "key.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "delay.h"

void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

u8 KEY_Scan(u8 mode)
{
    static u8 key_up = 1;
    if (mode == 1)
        key_up = 1;
    if (key_up && (KEY0 == 0U || KEY1 == 0U || WKUP == 1U))
    {
        delay_ms(20);
        key_up = 0; //has one of three KEY press
        if (KEY0 == 0)
            return KEY0_PRES;
        else if (KEY1 == 0)
            return KEY1_PRES;
        else if (WKUP == 1)
            return WKUP_PRES;
    }
    else if (KEY0 == 1 && KEY1 == 1 && WKUP == 0)
        key_up = 1; //no one of all
    return 0;
}
