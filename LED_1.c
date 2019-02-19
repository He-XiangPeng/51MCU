/*
*	点亮LED灯
*	开发板D1, D2, D6
*	sfr（Special Function Register特殊功能寄存器的缩写），sbit（特殊功能寄存器位）：
*   与定义一般的int、char型变量不同，这两个字定义的并不是变量，
*   而作为特殊功能寄存器的引用（地址或指针？），或许可以叫做别名
*/
#include <reg52.h> //	此文件中定义了单片机的一些特殊功能寄存器
sbit LED_1 = P2^0; // 将MCU P2.0端口定义为LED_1
sbit LED_2 = P2^1; // 将MCU P2.1端口定义为LED_2
sbit LED_6 = P2^5; // 将MCU P2.5端口定义为LED_5

void main()
{
	while(1)
	{
		LED_1 = 0;
		LED_2 = 0;
		LED_6 = 0;
	}
}