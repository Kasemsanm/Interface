#include <reg51.h>
#include <absacc.h>
#include <stdio.h>
#define PORT_C XBYTE[0x8002]
#define CON XBYTE[0x8003]

void start232(void)
{
    SCON = 0x52;
    TMOD = 0x20;
    TH1 = 0xFB;
    TR1 = 1;
}

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
    start232();
    while(1)
    {
        if(PORT_C == 0xFC)
        {
            printf("SWO = 0 and SW1 = 0 \r");
            delay(200);
        }
        else if(PORT_C == 0xFD)
        {
            printf("SWO = 1 and SW1 = 0 \r");
            delay(200);
        }
        else if(PORT_C == 0xFE)
        {
            printf("SWO = 0 and SW1 = 1 \r");
            delay(200);
        }
        else if(PORT_C == 0xFF)
        {
            printf("SWO = 1 and SW1 = 1 \r");
            delay(200);
        }
    }
}
