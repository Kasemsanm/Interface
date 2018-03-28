#include <reg51.h>
#include <absacc.h>
#include <stdio.h>
#define PORT_A XBYTE[0x8000]
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

void RL(void)
{
    unsigned int i;
    unsigned char data1[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
    for (i = 0 ; i < 8 ; i++)
    {
        PORT_A = data1[i];
        delay(500);
    }
}

void RR(void)
{
    unsigned int i;
    unsigned char data2[] = {0x80,0x40,0x20,0x10,0x01,0x02,0x04,0x08};
    for (i = 0 ; i < 8 ; i++)
    {
        PORT_A = data2[i];
        delay(500);
    }
}

void main()
{
    CON = 0x80;
    start232();
    PORT_A = 0x00;
    while(1)
    {
        unsigned char text;
        if(RI)
        {
            RI = 0;
            text = SBUF;
            if(text == 'A')
            {
                printf("A\n");
                RL();
            }
            else if (text == 'B')
            {
                printf("B\n");
                RR();
            }
            else
            {
                printf("Please press A or B\n");
                PORT_A == 0xFF;
            }
        }
        else{}    
    }
}
