nclude  <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE[0X8000]
#define CON XBYTE[0X8003]

char seg_data[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
		 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71}

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
	int i;
	CON=0x80;
	while(1)
	{
		for(i=0;i<=15,i++)
		{
			PORT_B = seg_data[i];
			delay(1000);
		}
	}
}

