/**
* 	LED灯闪烁
*
*/
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int uint;
sbit LED_1 = P2^0;

void delay(uint i)
{
	while(i--); // 当i为0时循环停止
}

void main()
{

// 单个LED闪烁
	while(1)
	{
		LED_1 = 0; // 点亮LED
		delay(50000);
		LED_1 = 1;	// 熄灭LED
		delay(50000);
	}
}
