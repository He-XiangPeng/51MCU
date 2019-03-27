/**
*	定时器中断0
*
*/
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int uint;
sbit LED = P2^2;

// 定时中断0初始化
void Timer0Init()
{
	TMOD |= 0x01;
	TH0 = 0xfc;
	TL0 = 0x18;
	ET0 = 1;
	EA  = 1;
	TR0 = 1;
}

void main()
{
	Timer0Init();
	while(1);
}

// 定时1s
void Timer0() interrupt 1
{
	static uint i;
	TH0 = 0xfc;
	TL0 = 0x18;
	i++;
	if(1000 == i) // 1s
	{
		i = 0;
		LED = ~LED;
	}	
}
