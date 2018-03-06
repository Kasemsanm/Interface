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

void rotateLeft()
{
	unsigned int i;
	unsigned char data1[] = 	

{0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	for(i=0;i<8;i++)
	{
		PORT_A = data1[i];
		delay(500);
	}
}

void rotateRight()
{
	unsigned int i;
	unsigned char data2[] = 			

{0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
	for(i=0;i<8;i++)
	{
		PORT_A = data2[i];
		delay(500);
	}
}

void main()
{
	CON = 0x89;
	PORT_A = 0x00;
	while(1)
	{
		if(PORT_C == 0xFC)
		{
			PORT_A = 0x00;
		}
		if(PORT_C == 0xFD)
		{
			rotateLeft();
		}
		if(PORT_C == 0xFE)
		{
			rotateRight();
		}
	}
}
