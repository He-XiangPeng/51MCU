/**
* 
*	静态数码管显示
*/
 //unsigned char Number[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
 //      0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};// 共阴极  码值
 //			    			{0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
 //                    0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};// 共阳极  码值
 // 0    1    2    3   4    5    6    7    8    9    a    b     c    d    e    f
 //                     a
 //                    --- 
 //					 f| g |b
 //					   ---
 //					 e|   |c
 //					   ---   .h
 //						  d
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

void main()
{
	LSA = 0;
	LSB = 0;
	LSC = 0;

	P0 = ledData[0];
	while(1);
}
