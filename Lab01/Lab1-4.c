nclude  <reg51.h>
#include <absacc.h>
#define PORT_A XBYTE[0x8000]
#define CON XBYTE[0x8003]

char data[]={0x81,0x42,0x24,0x18};

void display(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i=100;
		while(i>0)
		{
			i--;
			count--;
		}
	}
}


void main()
{
	int i;
	CON=0x80;
	while(1)
	{
		for(i=0;i<=3;i++)
		{
			PORT_A = display[i];
			delay(1000/(i+1)*(i+1));	
		}
		for(i=3;i>=0;i--)
		{
			PORT_A = display[i];
			delay(1000/(i+1)*(i+1));
		}
	}
}
