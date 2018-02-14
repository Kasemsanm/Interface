nclude <reg51.h>
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

void CountUp(int select)
{
	unsigned int i;
	PORT_A = 0x00;
	for(i=0;i<=9;i++)
	{
		delay(1000);
		if(select == 0)
			PORT_A++;
		else if(select == 1)
			PORT_A += 16;	
	}
	PORT_A = 0x00;
}

void CountDown(int select)
{
	unsigned int i;
	if(select == 0)
		PORT_A = 0x09;
	else if(select == 1)
		PORT_A = 0x90;
	for(i=0;i<=9;i++)
	{
		delay(1000);
		if(select == 0)
			PORT_A--;
		else if(select == 1)
			PORT_A -= 16;
	}
	PORT_A = 0x00;
}

void main()
{
	CON = 0x89;
	PORT_A = 0x00;
	while(1)
	{
		if(PORT_C == 0xFD)
		{
			CountDown(0);
		}
		if(PORT_C == 0xFC)
		{
			CountUp(0);
		}
		if(PORT_C == 0xFE)
		{
			CountDown(1);
		}
		if(PORT_C == 0xFF)
		{
			CountUp(1);
		}
	}
}
