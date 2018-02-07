nclude  <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE[0x8000]
#define PORT_B XBYTE[0x8001]
#define PORT_C XBYTE[0x8002]
#define CON XBYTE[0x8003]


void delay(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i=100;
		while(i>0)
		{
			i--;
		
		}
		count--;
	}
}


void main()
{
	CON=0x80;
	while(1)
	{
		PORT_A = 0x00;
		delay(1000);
		PORT_A = 0xFF;
		delay(1000);
	}
}
