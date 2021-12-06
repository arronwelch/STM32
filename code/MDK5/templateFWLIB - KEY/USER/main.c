#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"

int main(void)
{
  u8 t = 0;
  LED_Init();
  delay_init();
  KEY_Init();
  LED0 = 0;
  LED1 = 1;
  while (1)
  {
    t = KEY_Scan(0);
    switch (t)
    {
    case KEY0_PRES:
      LED0 = !LED0;
      break;
    case KEY1_PRES:
      LED1 = !LED1;
      break;
    case WKUP_PRES:
      LED0 = !LED0;
      LED1 = !LED1;
      break;
    default:
      delay_ms(20);
      break;
    }
  }
}
