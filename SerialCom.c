/**
 *	串口通信
 *
 * 
 */
#include <reg52.h>
typedef unsigned int uint;
typedef unsigned char uchar;

/**
 * 	串口初始化
 * 	波特率4800bps
 */
void UsartInit()
{
	TMOD = 0x20; // 高四位0010， 低四位0000
	TH1  = 0xf3;
	TL1  = 0xf3;
	PCON = 0x80; // 波特率加倍
	SCON = 0x50; // 0101 0000
	ES   = 1; // 打开串口中断
	EA   = 1;
}

void main()
{
	UsartInit();
	while(1);
}

void Usart() interrupt 4
{
	uchar receiveData; // 
	receiveData = SBUF;
	RI = 0;
	SBUF = receiveData;
	while(!TI);
	TI = 0; // 中断标志位置零
}

