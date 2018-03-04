nclude <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE [0X9000]
#define PORT_B XBYTE [0X9001]
#define PORT_C XBYTE [0X9002]
#define CON XBYTE [0X9003]
#define D0 = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09}
#define D1 = {0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90}

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
	unsigned int indexD0=0,indexD1=0;
	while(1)
	{
		delay(1000)
		if(PORT_C == 0xFD) // 00
		{
			if (indexD0 < 8)
				indexD0++;
			if (indexD1 < 8)
				indexD1++;
		}
		if(PORT_C == 0xFC) // 
		{
			if (indexD0 < 8)
				indexD0++;
			if (indexD1 < 8)
				indexD1++;
		}
		if(PORT_C == 0xFE)
		{
			if (indexD0 < 8)
				indexD0++;
			if (indexD1 < 8)
				indexD1++;
		}
		if(PORT_C == 0xFF)
		{
			if (indexD0 < 8)
				indexD0++;
			if (indexD1 < 8)
				indexD1++;
		}
		PORT_A = D0[indexD0]+D1[indexD1];
	}
}
