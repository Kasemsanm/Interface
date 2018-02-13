#include <reg51.h>		// นำไฟล์ reg51.h เข้ามาในโปรแกรม
#include <absacc.h>		// ไฟล์ absacc.h ใช้ในการเข้าถึงพื้นที่หน่วยความจำของ MCS-51
#define PORT_B XBYTE[0x8001]	// ประกาศ address PORT_B
#define CON XBYTE[0x8003]	// ประกาศ address CON

char seg_data[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
		 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71}
		 		// ประกาศตัวแปร array ชื่อ seg_data เพื่อเก็บค่า 0 ถึง F แบบ 7 segment
char seg_run[]={0x01,0x02,0x04,0x08,0x10,0x20};
				// ประกาศตัวแปร array ชื่อ seg_run เพื่อทำไฟวิ่ง
void delay(unsigned int count)		// โปรแกรม Delay รับ Parameter count เป็น int
{
	unsigned int i;			// ประกาศตัวแปล i เป็น unsigned int
	while(count)			// วบรอบทำงานไปเรื่่อยๆถ้า count ค่าอยู่ในช่วงของ unsigned int 
	{				// คือไม่ได้อยู่ในช่วง 0 ถึง 65535
		i=100;			// ให้ i มีค่าเท่ากับ 100
		while(i>0)		// วบรอบทำงานไปเรื่ือยๆถ้า i มากกว่า 0
		{
			i--;		// ให้ค่า i ลดลง 1 หรือเรียกได้ว่า i = i - 1
		}
		count--;		// ให้ค่า count ลดลง 1 หรือเรียกได้ว่า count = count - 1
	}
}					// สิ้นสุดโปรแกรม Delay

void main()				// โปรแกรมหลัก
{
	CON=0x80;			// ส่งคำสังไปที่พอร์ตควบคุม
	int i,j,k			// ประกาศตัวแปร i, j และ k เป็น int
	while(1)			// วนรอบทำงานไม่รู้จบ
	{
		for(i=0;i<=15,i++)	// วนรอบเพิ่มค่า i ครั้งล่ะ 1
		{
			PORT_B = seg_data[i];	// ส่งค่า seg_data ค่าที่ i ไปที่พอร์ต B
			delay(1000);		// เรียกใช้โปรแกรมย่อยเพื่อหน่วงเวลา โดยให้ count มีค่า 1000
			for(j = 0;j<i;j++){	// วนรอบเพิ่มค่า j ครั้งล่ะ 1
				for(k = 0;k<=6;k++) // วนรอบเพิ่มค่า k ครั้งล่ะ 1
				{
					PORT_B = seg_run[k]; // ส่งค่า seg_run ค่าที่ k ไปที่พอร์ต B
					delay(500); // เรียกใช้โปรแกรมย่อยเพื่อหน่วงเวลา โดยให้ count มีค่า 500
				}
		}
	}
}					// สิ้นสุดโปรแกรมหลัก

