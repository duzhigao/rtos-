#include "sys.h"
#include "uart.h"
#include <stdio.h>

char g_Char = 'A';           // �ɶ���д�����ܷ���ROM�ϣ�Ӧ�÷���RAM��
const char g_Char2 = 'B';    // ֻ�����������Է���ROM��
int g_A = 0;   // ��ʼֵΪ0�������˷ѿռ䱣����ROM�ϣ�û��Ҫ
int g_B;       // û�г�ʼ���������˷ѿռ䱣����ROM�ϣ�û��Ҫ

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
			putchar((char)c); /*arm gcc������Ĭ��charλunsigned char*/
		
	}
	
}