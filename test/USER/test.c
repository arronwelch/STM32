#include "sys.h"
#include "usart.h"
#include "delay.h"
int main(void)
{
	u8 t = 0;
	Stm32_Clock_Init(9);//72M
	delay_init(72);//delay init
	uart_init(72,9600);//setting uart1 baud rate
	while(1)
	{
		printf("t:%d\r\n",t);//CR = Carriage Return  and LF = Line Feed (Windows)
		delay_ms(500);
		t++;
	}
}
