#include <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE [0XA000]
#define PORT_B XBYTE [0XA001]
#define PORT_C XBYTE [0XA002]
#define CON XBYTE [0XA003]

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

void cw()
{
	PORT_B = 0x01;
	delay(50);
	PORT_B = 0x02;
	delay(50);
	PORT_B = 0x04;
	delay(50);
	PORT_B = 0x08;
	delay(50);
}


void ccw()
{
	PORT_B = 0x08;
	delay(50);
	PORT_B = 0x04;
	delay(50);
	PORT_B = 0x02;
	delay(50);
	PORT_B = 0x01;
	delay(50);
}

void stop()
{
	PORT_B = 0x00;
}

void main()
{
	int i;
	CON = 0x90;
	while(1)
	{
		if(PORT_A == 0xFC)
		{
			stop();
			i = 0;
		}
		else if(PORT_A == 0xFD)
		{
			cw();
			i = 1;
		}
		else if(PORT_A == 0xFE)
		{
			ccw();
			i = 2;
		}
		else
		{
			if(i == 0)
			{
				stop();
			}
			else if(i == 1)
			{
				cw();
			}
			else if(i == 2)
			{
				ccw();
			}
		}
	}
}
