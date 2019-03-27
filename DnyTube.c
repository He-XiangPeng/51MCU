/**
*	动态数码管显示
*
* 
*/
#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int uint;
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

uchar code ledData[] = {
	0x3f, // '0'
	0x06, // '1'
	0x5b, // '2'
	0x4f, // '3'
	0x66, // '4'
	0x6d, // '5'
	0x7d, // '6'
	0x07, // '7'
	0x7f, // '8'
	0x6f, // '9'
	0x77, // 'a'
	0x7c, // 'b'
	0x39, // 'c'
	0x5e, // 'd'
	0x79, // 'e'
	0x71  // 'f'
}; // code是程序储存空间

void delay(uchar i);
void digtubeDisplay(void);

void main(void)
{
	while(1)
	{
		digtubeDisplay();
	}
}

void delay(uchar i)
{
	while(i--); // 当i为0时循环停止
}

void digtubeDisplay(void)
{
	uchar i;
	for(i = 0; i < 8; i++)
	{
		switch(i)
		{
			case(0):
				LSA = 0;
				LSB = 0; 
				LSC = 0; 
				break;
			case(1):
				LSA = 1;
				LSB = 0; 
				LSC = 0; 
				break;
			case(2):
				LSA = 0;
				LSB = 1; 
				LSC = 0; 
				break;
			case(3):
				LSA = 1;
				LSB = 1; 
				LSC = 0; 
				break;
			case(4):
				LSA = 0;
				LSB = 0; 
				LSC = 1; 
				break;
			case(5):
				LSA = 1;
				LSB = 0; 
				LSC = 1; 
				break;
			case(6):
				LSA = 0;
				LSB = 1; 
				LSC = 1; 
				break;
			case(7):
				LSA = 1;
				LSB = 1; 
				LSC = 1; 
				break;
		}
		
		P0 = ledData[i];
		delay(10);
		P0 = 0x00;	
	}
}
