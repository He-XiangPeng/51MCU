/**
* 流水灯实验
*
*/
#include <reg52.h>
#include <intrins.h>
// 宏名用大写
#define UCHAR unsigned char 
#define UINT unsigned int
#define LED P2

void delay(uint z)
{
	while(z--);
}

void main()
{
	uchar i;
	LED = 0x7f; // BIN 0111 1111 P27最高位置零
	// LED = 0xfe; // BIN 1111 1110
	delay(5000);

	while(1)
	{
		for(i = 0; i < 7; i++)
		{	
			LED = _cror_(LED, 1); // 字符循环右移一位
			delay(50000);
		}
		
		for(i = 0; i < 7; i++)
		{	
			LED = _crol_(LED, 1); // 字符循环左移一位
			delay(50000);
		}
		
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
	
