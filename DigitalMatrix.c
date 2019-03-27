/**
* 
*	动态数码管显示
*    
*/
#include <reg51.h>
#include <intrins.h>
typedef unsigned char uchar;
typedef unsigned int uint;
sbit SRCLK = P3^6;
sbit RCLK = P3^5;
sbit SER = P3^6;

// 显示阿拉伯数字0
uchar ledduan[] = {0x00, 0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e};
uchar ledwei[] = {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};
void delay(uchar i);
void HC595SendByte(uchar dat);

void main()
{
    // HC595SendByte(0x80);
    // P0 = 0x7f;
    uchar i;
	while(1)
    {
        p0 = 0x7f;
        for(i = 0; i < count; i++)
        {
            P0 = ledwei[i];
            HC595SendByte(ledduan[i]);
            delay(100);
            HC595SendByte(0x00);
        }      
    }
}

void delay(uchar i)
{
    while(i--);
}

void HC595SendByte(uchar dat)
{
    uchar i;
    SRCLK = 0;
    RCLK = 0;
    for(i = 0; i < 8; i++)
    {
        SER = dat >> 7;
        dat <<= 1;  // 1  0011 0010
        SRCLK = 1;
        _nop_();
        _nop_();
        SRCLK = 0;
    }
    RCLK = 1;
    _nop_();
    _nop_();
    RCLK = 0;
}
