#ifndef _DRIVER_USART_H
#define _DRIVER_USART_H

#include <stdio.h>

int fgetc(FILE *file);
int fputc(int c,FILE *file);
void EnableDebugIRQ(void);
void DisableDebugIRQ(void);
void USART1_IRQHandler(void);
#endif