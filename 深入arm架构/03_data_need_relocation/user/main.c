#include "sys.h"
#include "uart.h"
#include <stdio.h>

char g_Char = 'A';           // 可读可写，不能放在ROM上，应该放在RAM里
const char g_Char2 = 'B';    // 只读变量，可以放在ROM上
int g_A = 0;   // 初始值为0，干嘛浪费空间保存在ROM上？没必要
int g_B;       // 没有初始化，干嘛浪费空间保存在ROM上？没必要

int main(void)
{
	signed char c;
	System_Clock_Init();
	Inital_Uart1();
	putchar('d');
	putchar('z');
	putchar('g');
	putchar(g_Char2);
	putchar(g_Char);


	
	
	while(1)
	{
		c = (signed char)getchar();
		if(c != -1)
			putchar((char)c); /*arm gcc编译器默认char位unsigned char*/
		
	}
	
}