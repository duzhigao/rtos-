#include "sys.h"
#include "uart.h"
#include <stdio.h>

char g_Char = 'A';           // �ɶ���д�����ܷ���ROM�ϣ�Ӧ�÷���RAM��
const char g_Char2 = 'B';    // ֻ�����������Է���ROM��
int g_A[3] = {0};   //����keil������Ż�������8���ֽڵĳ�ʼ��Ϊ0�Ļ�û��ʼ���ģ�����8���ֽڷ��ڲŷ���bss��С�ڵ���8���ֽڷ���data
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
			putchar((char)c); /*arm gcc������Ĭ��charλunsigned char*/
		
	}
	
}