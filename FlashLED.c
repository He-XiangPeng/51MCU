/**
* LED灯闪烁
*
*/
#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit LED_1 = P2^0;
uint a;
uint b;
void main()
{

// 单个LED闪烁
	while(1)
	{
		LED_1 = 0; // 点亮LED
		// a = 3000;
		a = 50000;
		while(a--);
		LED_1 = 1;	// 熄灭LED
		// a = 3000;
		b = 50000;
		while(b--);
	}

}
