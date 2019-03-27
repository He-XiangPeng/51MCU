/**
*  显示动态字符
*  清翔单片机教程
*/
 //unsigned char Number[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};// 共阴极  码值
 //			    {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};// 共阳极  码值
 //                         0    1    2    3   4    5    6    7    8    9    a    b     c    d    e    f
 //                     a
 //                    --- 
 //					 f| g |b
 //					   ---
 //					 e|   |c
 //					   --- .h
 //						d
#include <reg52.h>
#define UCHAR unsigned char
#define UINT unsigned int
sbit we = P2^7;
sbit du = P2^6;

UCHAR code ledData[] = {
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


void delay(UINT i)
{
	while(i--); // 当i为0时循环停止
}

void main()
{
    while(1)
    {
        we = 1;
        P0 = 0xfe; // 点亮第一位数码管
        we = 0;

        du = 1;
        P0 = ledData[1];
        du = 0;
        delay(1);

        we = 1;
        P0 = 0xfd; // 点亮第二位数码管
        we = 0

        du = 1;
        P0 = ledData[2];
        du = 0;
        delay(1);

        we = 1;
        P0 = 0xfb; // 点亮第三位数码管
        we = 0

        du = 1;
        P0 = ledData[3];
        du = 0;
        delay(1);

        we = 1;
        P0 = 0xf7; // 点亮第四位数码管
        we = 0

        du = 1;
        P0 = ledData[4];
        du = 0;
        delay(1);

        we = 1;
        P0 = 0xef; // 点亮第五位数码管
        we = 0

        du = 1;
        P0 = ledData[5];
        du = 0;
        delay(1);

        we = 1;
        P0 = 0xdf; // 点亮第六位数码管
        we = 0

        du = 1;
        P0 = ledData[6];
        du = 0;
        delay(1);

        we = 1;
        P0 = 0xbf; // 点亮第七位数码管
        we = 0

        du = 1;
        P0 = ledData[7];
        du = 0;
        delay(1);

        we = 1;
        P0 = 0x7f; // 点亮第八位数码管
        we = 0

        du = 1;
        P0 = ledData[3];
        du = 0;
        delay(1);

    }
}
