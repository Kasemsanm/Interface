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

void setSpeed(unsigned int x)
{
	PORT_B = 0x0c;
	delay(x);
	PORT_B = 0x06;
	delay(x);
	PORT_B = 0x03;
	delay(x);
	PORT_B = 0x09;
	delay(x);
}

void stop()
{
	PORT_B = 0x00;
}

void main()
{
	unsigned int x;
	CON = 0x90;
	stop();
	while(1)
	{
		if(PORT_A == 0xF9)
		{
			x = 100;
			setSpeed(x);
		}
		else if(PORT_A == 0xFA)
		{
			x = 50;
			setSpeed(x);
		}
		else if(PORT_A == 0xFC)
		{
			x = 25;
			setSpeed(x);
		}
		else
		{			
			setSpeed(x);
		}
	}
}
