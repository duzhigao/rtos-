#include "sys.h"
#include "uart.h"
#include <stdio.h>

char g_Char = 'A';           // 可读可写，不能放在ROM上，应该放在RAM里
const char g_Char2 = 'B';    // 只读变量，可以放在ROM上
int g_A[3] = {0};   //由于keil编译的优化，大于8个字节的初始化为0的或没初始化的，大于8个字节放在才放在bss，小于等于8个字节放在data
char g_B[9];       

int main(void)
{
	signed char c;
	System_Clock_Init();
	Inital_Uart1();
	putchar('d');
	putchar('z');
	putchar('g');
	putchar(g_A[0]);
	putchar(g_B[0]);


	
	
	while(1)
	{
		c = (signed char)getchar();
		if(c != -1)
			putchar((char)c); /*arm gcc编译器默认char位unsigned char*/
		
	}
	
}