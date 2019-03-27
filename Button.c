/**
* 独立按键，控制LED灯状态的翻转
*
*/
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int uint;

sbit LED_1 = P2^0;
sbit K1 = P3^1; // 按键K1

void delay(uint i)
{
	while(i--); // 当i为0时循环停止
}

void keypros(void)
{
	if(0 == K1) // 按键是否按下
	{
		delay(1000); // 消抖
		if(0 == K1)  // 再次判断按键是否按下
			LED_1 = ~LED_1;
		while(!K1); // 
	}
}

void main()
{
	// 单个LED闪烁
	while(1)
	{
		keypros();
	}
}
