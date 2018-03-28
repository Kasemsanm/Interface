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
    while(1)
    {
        unsigned char num;
        if(RI)
        {
            RI = 0;
            num = SBUF;
            if(num == '0')
            {
                printf("0\n");
                PORT_B = 0x3F;
            }
            else if (num == '1')
            {
                printf("1\n");
                PORT_B = 0x06;
            }
            else if (num == '2')
            {
                printf("2\n");
                PORT_B = 0x5B;
            }
            else if (num == '3')
            {
                printf("3\n");
                PORT_B = 0x4F;
            }
            else if (num == '4')
            {
                printf("4\n");
                PORT_B = 0x66;
            }
            else if (num == '5')
            {
                printf("5\n");
                PORT_B = 0x6D;
            }
            else if (num == '6')
            {
                printf("6\n");
                PORT_B = 0x7D;
            }
            else if (num == '7')
            {
                printf("7\n");
                PORT_B = 0x07;
            }
            else if (num == '8')
            {
                printf("8\n");
                PORT_B = 0x7F;
            }
            else if (num == '9')
            {
                printf("9\n");
                PORT_B = 0x6F;
            }
            else{}
        }
        else{}    
    }
}
