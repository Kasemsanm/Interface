#include <reg51.h>				// นำไฟล์ reg51.h เข้ามาในโปรแกรม
#include <absacc.h>				// ไฟล์ absacc.h ใช้ในการเข้าถึงพื้นที่หน่วยความจำของ MCS-51
#define PORT_A XBYTE[0x8000]			// ประกาศ address PORT_A
#define CON XBYTE[0x8003]			// ประกาศ address CON

char LED[]={0x81,0x42,0x24,0x18};		// ประกาศตัวแปร array ชื่อ LED เพื่อเก็บค่า 0x81,0x42,0x24,0x18

void delay(unsigned int count)			// โปรแกรม Delay รับ Parameter count เป็น int
{
	unsigned int i;				// ประกาศตัวแปล i เป็น unsigned int
	while(count)				// วบรอบทำงานไปเรื่่อยๆถ้า count ค่าอยู่ในช่วงของ unsigned int 
	{					// คือไม่ได้อยู่ในช่วง 0 ถึง 65535
		i=100;				// ให้ i มีค่าเท่ากับ 100
		while(i>0)			// วบรอบทำงานไปเรื่ือยๆถ้า i มากกว่า 0
		{
			i--;			// ให้ค่า i ลดลง 1 หรือเรียกได้ว่า i = i - 1
		}
		count--;			// ให้ค่า count ลดลง 1 หรือเรียกได้ว่า count = count - 1
	}
}						// สิ้นสุดโปรแกรม Delay

void main()					// โปรแกรมหลัก
{
	CON=0x80;				// ส่งคำสังไปที่พอร์ตควบคุม
	int i					// ประกาศตัวแปร i เป็น int
	while(1)				// วนรอบทำงานไม่รู้จบ
	{
		for(i=0;i<=3;i++)		// วนรอบเพิ่มค่า i ครั้งล่ะ 1
		{
			PORT_A = LED[i];	// ส่งค่า LED ค่าที่ i ไปที่พอร์ต A
			delay(1000/(i+1)*(i+1));// เรียกใช้โปรแกรมย่อยเพื่อหน่วงเวลา โดยให้ count มีค่า 1000/(i+1)*(i+1)
		}
		for(i=3;i>=0;i--)		// วนรอบลดค่า i ครั้งล่ะ 1
		{
			PORT_A = LED[i];	// ส่งค่า LED ค่าที่ i ไปที่พอร์ต A
			delay(1000/(i+1)*(i+1));// เรียกใช้โปรแกรมย่อยเพื่อหน่วงเวลา โดยให้ count มีค่า 1000/(i+1)*(i+1)
		}
	}
}						// สิ้นสุดโปรแกรมหลัก
