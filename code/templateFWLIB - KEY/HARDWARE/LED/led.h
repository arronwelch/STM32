
#ifndef __LED_H__
#define __LED_H__
#include "sys.h"
#include "stm32f10x.h"

#define LED0 PAout(8)
#define LED1 PDout(2)

void LED_Init(void);

#endif
