#include <reg51.h>
#include <stdio.h>

void start232(void)
{
    SCON = 0x52;
    TMOD = 0x20;
    TH1 = 0xFB;
    TR1 = 1;
}

void main()
{
    start232();
    while(1)
    {
        printf("HELLO ENGINEER\n\r");
    }
}
