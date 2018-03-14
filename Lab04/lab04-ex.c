#include <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE [0X9000]
#define PORT_B XBYTE [0X9001]
#define PORT_C XBYTE [0X9002]
#define CON XBYTE [0X9003]

void delay(unsigned int count)
{
	TH0 = 0xD8;
	TL0 = 0xEF;
	TF0 = 0;
	TR0 = 1;
	while(count)
	{
		while(!TF0);
		TF0 = 0;
		TH0 = 0xD8;
		TL0 = 0xEF;
		count--;
	}
	TR0 = 0;
}

void stop()
{
	PORT_A = 0x00;
}

void cw(int time)
{
	char PORT_C_SW = PORT_C;
	PORT_A = 0x01;
	delay(100*time);
	PORT_A = 0x00;
	while(PORT_C != PORT_C_SW){}
}
void main()
{
	int i;
	CON = 0x89;
	TMOD = 0x01;
	stop();
	while(1)
	{
		if(PORT_C == 0xFC)
		{
			stop();
		}
		else if(PORT_C == 0xFD)
		{
			cw(5);
		}
		else if(PORT_C == 0xFE)
		{
			cw(10);
		}
		else if(PORT_C == 0xFF)
		{
			cw(15);
		}
	}
}
