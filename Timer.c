/**
 *  定时器的使用
 *  清翔单片机教程
 *  
 */

#include <reg52.h>
typedef unsigned char uchar;
typedef unsigned int uint;

uchar counter, time_counter;
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
sbit we = P2^7;
sbit du = P2^6;
sbit LED_1 = P2^0;

void display(uchar i);

void main()
{
    TMOD = 0x10; // 定时器1，工作模式1，16位模式定时器
    TH1 = 0x4b;
    TL = 0xfe; // 定时50ms
    TR1 = 1; // 启动定时器
    while(1)
    {
        if (TF1 == 1) 
        {
            TF1 = 0;
            TH1 = 0x4b;
            TL = 0xfe;
            counter++;
        }
        
        if (counter == 20) 
        {
            counter = 0;
            LED_1 = ~LED_1;
            time_counter++;
        }

        if (time_counter == 60) 
        {
            time_counter = 0;
        }
        display(time_counter);

        
        
    }
}

void display(uchar i)
{
    uchar shi, ge;
    shi = i / 10;
    ge = i % 10;
    we = 1;
    P0 = 0xfe; // 点亮第一位数码管
    we = 0;

    du = 1;
    P0 = ledData[shi];
    du = 0;

    we = 1;
    P0 = 0xfd; // 点亮第二位数码管
    we = 0

    du = 1;
    P0 = ledData[ge];
    du = 0;
}