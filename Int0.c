/**
*	外部中断0
*	外部中断1，同外部中断0
*
*/
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int uint;
sbit LED = P2^0;
sbit K3 = P3^2; // K3按键
sbit K4 = P3^3; // K4 Button

void delay(uint i)
{
	while(i--);
}

// 外部中断0
void Int0Init()
{
	IT0 = 1; // 请求中断0
	EX0 = 1; // 允许中断0
	EA  = 1; //cpu总中断
}

// 外部中断1
void Int1Init()
{
	IT1 = 1; // 请求中断1
	EX1 = 1; // 允许中断1
	EA  = 1; //cpu总中断
}

void main()
{
	Int0Init();
	Int1Init();
	while(1);
}

void Int0() interrupt 0
{
	delay(1000);
	if(K3 == 0)
	{
		LED = ~LED;
	}
}

void Int1() interrupt 2
{
	delay(1000);
	if(K4 == 0)
	{
		LED = ~LED;
	}
}