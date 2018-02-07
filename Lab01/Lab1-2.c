nclude  <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE[0x8000]
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
	PORT_A=0x01;
	while(1)
	{
		delay(1000);
		PORT_A = PORT_A << 1;
		if(PORT_A == 0x80)
		PORT_A = 0x01;
	}
}
