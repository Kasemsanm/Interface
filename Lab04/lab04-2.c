#include <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE [0X9000]
#define PORT_B XBYTE [0X9001]
#define PORT_C XBYTE [0X9002]
#define CON XBYTE [0X9003]

void delay(unsigned int count)
{
	TH0 = 0x0F;
	TL0 = 0xFC;
	TF0 = 0;
	TR = 1;
	while(count)
	{
		while(!TF0);
		TF = 0;
		TH0 = 0x0F;
		TL0 = 0xFC;
		count--;
	}
	TR0 = 0;
}

void stop()
{
	PORT_A = 0x00;
}

void cw3()
{
	PORT_A = 0x01;
}

void cw2()
{
	PORT_A = 0x01;
	delay(3);
	PORT_A = 0x00;
	delay(2);
}

void cw1()
{
	PORT_A = 0x01;
	delay(1);
	PORT_A = 0x00;
	delay(2);
}

void main()
{
	int i;
	CON = 0x89;
	TMOD = 0x01;
	stop();
	while(1)
	{
		if(PORT_C == 0xF9)
		{
			cw1();
			i = 1;
		}
		else if(PORT_C == 0xF9)
		{
			cw2();
			i = 2;
		}
		else if(PORT_C == 0xF9)
		{
			cw3();
			i = 3;
		}
		else 
		{
			if(i==1)
			{
				cw1();
			}
			else if(i==2)
			{
				cw2();
			}
			else if(i==3)
			{
				cw3();
			}
		}

	}
}
