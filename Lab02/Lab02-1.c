#include <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE [0X9000]
#define PORT_B XBYTE [0X9001]
#define PORT_C XBYTE [0X9002]
#define CON XBYTE [0X9003]

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
	CON = 0x89;
	PORT_A = 0x00;
	while(1)
	{
		if(PORT_C == 0xFD)
		{
			delay(50);
			PORT_A = PORT_A + 1;
			while(PORT_C == 0xFD){}	
		}
		if(PORT_C == 0xFE)
		{
			delay(50);
			PORT_A = PORT_A - 1;
			while(PORT_C == 0xFE){}	
		}
	}
}

