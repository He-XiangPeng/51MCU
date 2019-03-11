/**
*	蜂鸣器发声
*
*
*/
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int uint;
sbit beep = P1^5;

void delay(uint i)
{
	while(i--);
}

void main()
{

	uint k = 100;
	while(1)
	{
		beep = ~beep;
		delay(k); // 改变k的取值以改变频率，发出不同音高的声音
	}
	
}