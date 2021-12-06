
#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f10x_gpio.h"
#include "sys.h"

#define KEY0 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5)
#define KEY1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
#define WKUP GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)

#define KEY0_PRES 1
#define KEY1_PRES 2
#define WKUP_PRES 3

void KEY_Init(void);
u8 KEY_Scan(u8 mode);

#endif
