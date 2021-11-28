#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

int main(void)
{
  LED_Init();
  delay_init();
  while (1)
  {
    GPIO_SetBits(GPIOA,GPIO_Pin_8);
    GPIO_SetBits(GPIOD,GPIO_Pin_2);
    delay_ms(500);
    GPIO_ResetBits(GPIOA,GPIO_Pin_8);
    GPIO_ResetBits(GPIOD,GPIO_Pin_2);
    delay_ms(500);
  }
}
