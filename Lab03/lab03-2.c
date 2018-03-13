#include <reg51.h>	// นำไฟล์ reg51.h เข้ามาในโปรแกรม
#include <absacc.h>		// นำไฟล์ absacc.h เข้ามาในโปรแกรม
#define PORT_A XBYTE [0XA000] //ประกาศ address Port A
#define PORT_B XBYTE [0XA001] //ประกาศ address Port B
#define PORT_C XBYTE [0XA002] //ประกาศ address Port C
#define CON XBYTE [0XA003] //ประกาศ address Control Port

void delay(unsigned int count)	// โปรแกรม Delay รับ Parameter count เป็น int
{
	unsigned int i;		// ประกาศตัวแปล i เป็น unsigned int
	while(count)		// วบรอบทำงานไปเรื่อยๆถ้า count ค่าอยู่ในช่วงของ unsigned int 
	{			// คือไม่ได้อยู่ในช่วง 0 ถึง 65535
		i=100;		// ให้ i มีค่าเท่ากับ 100
		while(i>0)	// วบรอบทำงานไปเรื่ือยๆถ้า i มากกว่า 0
		{
			i--;	// ให้ค่า i ลดลง 1 หรือเรียกได้ว่า i = i - 1
		}
		count--;	// ให้ค่า count ลดลง 1 หรือเรียกได้ว่า count = count - 1
	}
}				// สิ้นสุดโปรแกรม Delay

void seg7()
{
    delay(20);
    PORT_A = PORT_A + 1;
    while (PORT_B == 0xFF){}
}

void main()
{
    CON = 0x82;
    PORT_A = 0x00;
    while (PORT_A != 0xFF)
    {
        if(PORT_B == 0xFF)
        {
            seg7()
        }      
    }
    while(1){}
}