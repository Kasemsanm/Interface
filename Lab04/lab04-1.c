#include <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE [0X9000]
#define PORT_B XBYTE [0X9001]
#define PORT_C XBYTE [0X9002]
#define CON XBYTE [0X9003]

void stop()
{
	PORT_A = 0x00;
}

void cw()
{
	PORT_A = 0x01;
}

void ccw()
{
	PORT_A = 0x02;
}

void main()
{
	CON = 0x89;
	while(1)
	{
		if(PORT_C == 0xFC)
		{
			stop();
		}
		else if(PORT_C == 0xFD)
		{
			stop();
		}
		else if(PORT_C == 0xFE)
		{
			cw();
		}
		else if(PORT_C == 0xFF)
		{
			ccw();
		}
	}
}
