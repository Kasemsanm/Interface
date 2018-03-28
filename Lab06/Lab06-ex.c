#include <reg51.h>
#include <absacc.h>
#include <stdio.h>
#define PORT_B XBYTE[0x8001]
#define CON XBYTE[0x8003]

void start232(void)
{
    SCON = 0x52;
    TMOD = 0x20;
    TH1 = 0xFB;
    TR1 = 1;
}

void main()
{
    CON = 0x80;
    start232();
    PORT_B = 0x00;
    while(1)
    {
        unsigned char num;
        if(RI)
        {
            RI = 0;
            symbol = SBUF;
            if(symbol == '+')
            {
                if(PORT_B < 255)
                {
                    PORT_B++;
                }
            }
            else if (symbol == '-')
            {
                if(PORT_B > 0)
                {
                    PORT_B--;
                }
            }
            else{}
        }
        else{}    
    }
}
