/**
* 流水灯实验
*
*/
#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit LED_1 = P2^0;
uint a;
uchar i;
unsigned temp;

void delay(uint z); // 函数原型

void main()
{

	temp = 0x7f; // BIN 0111 1111 P27最高位置零
	// temp = 0xfe; // BIN 1111 1110
	P2 = temp;
	while(1)
	{
		for(i = 0; i < 8; i++)
		{	
			temp = _cror_(temp, 1);
			//temp = _crol_(temp, 1);
			P2 = temp;
			delay(2000);
		}
	}
	
// 
/**
	temp = 0x7f; // BIN 0111 1111 P27最高位置零
	// temp = 0xfe; // BIN 1111 1110
	P2 = temp;
	while(1)
	{
		for(i = 0; i < 8; i++)
		{	
			temp = _cror_(temp, 1);
			//temp = _crol_(temp, 1);
			P2 = temp;
			a = 30000;
			while(a--);
		}
	}
*/
	
//	改变i的范围，改变点亮灯的数量
/**
	while(1)
	{
		for(i = 0; i < 5; i++)
		{	
			P2 = P2 << 1;
			a = 65535;
			while(a--);
		}
		P2 = 0xff; // 二进制1111 1111
		a = 65535;
		while(a--);
	}
*/
	
//	D1-D8依次点亮
/**
	while(1)
	{
		P2 = P2 << 1;
		a = 65535;
		while(a--);
		if(P2 == 0)
		{
			P2 = 0xff; // 二进制1111 1111
			a = 65535;
			while(a--);
		}
	}
*/
	
}

void delay(uint z)
{
	uint x, y;
	for(x = z; x > 0; x--)
		for(y = 120; y > 0; y--);
}	
