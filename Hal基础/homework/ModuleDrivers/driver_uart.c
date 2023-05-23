#include "driver_uart.h"
#include "string.h"
#include "usart.h"

void DebugPrint(char *str){
	uint16_t len = strlen(str);
	HAL_UART_Transmit(&huart1,(uint8_t *)str,len,300);
}

void DegbugGet(char *buf,uint16_t size){
	while(HAL_UART_Receive(&huart1,(uint8_t *)buf,size,300));
}

int fputc(int c,FILE *f){
	while(HAL_UART_Transmit(&huart1,(uint8_t *)&c,1,300));
}

int fgetc(FILE *f){
	volatile char c;
	while(HAL_UART_Receive(&huart1,(uint8_t *)&c,1,300));
	return c;
}