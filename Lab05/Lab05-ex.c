#include <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE [0XA000]
#define PORT_B XBYTE [0XA001]
#define PORT_C XBYTE [0XA002]
#define CON XBYTE [0XA003]

void delay(unsigned int count)
{
	TH0 = 0xFC;
	TL0 = 0x17;
	TF0 = 0;
	TR0 = 1;
	while(count)
	{
		while(!TF0);
		TF0 = 0;
		TH0 = 0xFC;
		TL0 = 0x17;
		count--;
	}
	TR0 = 0;
}

void stop()
{
	PORT_B = 0x00;
}

void cw(unsigned int time)
{
	char sw = PORT_A;
	while(time > 0){
		int i = 0;
		for(i ; i < 25; i++){
			PORT_B = 0x09;
			delay(10);
			PORT_B = 0x03;
			delay(10);
			PORT_B = 0x06;
			delay(10);
			PORT_B = 0x0c;
			delay(10);
		}
		time--;
	}
	stop();
	while(sw == PORT_A){}
}

void main()
{
	unsigned int x;
	CON = 0x90;
	TMOD = 0x01;
	stop();
	while(1)
	{
		if(PORT_A == 0xFC)
		{
			stop();
		}
		else if(PORT_A == 0xFD)
		{
			cw(5);
		}
		else if(PORT_A == 0xFE)
		{
			cw(10);
		}
		else if(PORT_A == 0xFF)
		{			
			cw(15);
		}
	}
}
