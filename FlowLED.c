/**
* 依次点亮2，4，6，8的LED灯
*
*/
#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define LED P2

void delay(uint z)
{
	while(z--);
}

void main()
{
	while (1)
	{
		P2 = 0x55; // P2口有8位，看作一个字节
		delay(1000);
		P2 = 0xff;
		delay(1000);
	}
}	

	
