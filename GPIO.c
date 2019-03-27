/**
* 
* 矩阵按键，控制数码管
* 
*/
#include <reg52.h>
#define GPIO_KEY P1
#define GPIO_DIG P0
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

uchar KeyValue;
void keydown(void);
void delay(uchar i);

void main()
{
	LSA = 0;
	LSB = 0;
	LSC = 0;
	
	while(1)
	{
		keydown();
		GPIO_DIG = ledData[KeyValue];
	}
}

void delay(uchar i)
{
	while(i--); // 当i为0时循环停止
}

void keydown(void)
{
	uchar a = 0;
	GPIO_KEY = 0x0f; // 0000 1111
	if(GPIO_KEY != 0x0f)
	{
		delay(1000);
		if(GPIO_KEY != 0x0f)
		{
			GPIO_KEY = 0x0f; // 低4位高电平0000 1111
			switch(GPIO_KEY)
			{
				case(0x07):
					KeyValue = 0;
					break;
				case(0x0b):
					KeyValue = 1;
					break;
				case(0x0d):
					KeyValue = 2;
					break;
				case(0x0e):
					KeyValue = 3;
					break;
			}
			
			GPIO_KEY = 0xf0;  // 低4位低电平1111 0000
			switch(GPIO_KEY)
			{
				case(0x70):
					KeyValue = KeyValue;
					break;
				case(0xb0):
					KeyValue += 4;
					break;
				case(0xd0):
					KeyValue += 8;
					break;
				case(0xe0):
					KeyValue += 12;
					break;
			}
			
			while((a < 50) && (GPIO_KEY != 0xf0))
			{
				delay(1000);
				a++;
			}		
		}
	}
}
