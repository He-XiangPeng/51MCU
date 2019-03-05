/**
*  循环显示静态字符
*
*/
 //unsigned char Number[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};// 共阴极  码值
 //			    {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};// 共阳极  码值
 //                         0    1    2    3   4    5    6    7    8    9    a    b     c    d    e    f
 //<span style="white-space:pre">					</span>    a
 //<span style="white-space:pre">					</span>   --- 
 //					 f| g |b
 //					   ---
 //					 e|   |c
 //					   --- .h
 //						d
#include <reg52.h>
#define uchar unsigned char
typedef unsigned int uint;
sbit we = P2^7;
sbit du = P2^6;
uchar i = 0;

uchar code ledData[i] = {
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


void delay(uint i)
{
	while(i--); // 当i为0时循环停止
}

void main()
{
    while(1)
    {
        du = 1; // 打开段选
        P0 = ledData[i];
        du = 0; // 关闭段选
        // delay(5);

        we = 1; // 打开位选
        P0 = 0;
        we = 0; // 关闭位选
        delay(500);
        i++;
        if (i == 10) 
        {
            i = 0;
        }
    }
	

	
}
