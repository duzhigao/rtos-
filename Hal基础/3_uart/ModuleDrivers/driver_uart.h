#ifndef _DRIVER_UART_H
#define _DRIVER_UART_H
#include "stm32f1xx_hal.h"
#include "stdio.h"	
void DebugPrint(char *str);
void DegbugGet(char *buff,uint16_t size);
int fputc(int c,FILE *f);
int fgetc(FILE *f);
#endif
