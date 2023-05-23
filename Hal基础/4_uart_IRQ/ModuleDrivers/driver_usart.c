#include "driver_usart.h"
#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef huart1;
static volatile uint8_t txcplt_flag = 0;
static volatile uint8_t rxcplt_flag = 0;
void EnableDebugIRQ(void)
{
	HAL_NVIC_SetPriority(USART1_IRQn,0,1);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
	
}

void DisableDebugIRQ(void)
{
	HAL_NVIC_DisableIRQ(USART1_IRQn);
}
int fgetc(FILE *file)
{
	rxcplt_flag = 0;
	char c = 0;
	HAL_UART_Receive_IT(&huart1,(uint8_t *)&c,1);
	while(rxcplt_flag == 0);
	return c;
	
}
int fputc(int c,FILE *file)
{
	txcplt_flag = 0;
	HAL_UART_Transmit_IT(&huart1,(uint8_t *)&c,1);
	while(txcplt_flag == 0);
	return c;
}

void USART1_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
		rxcplt_flag = 1;
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
		txcplt_flag = 1;
}
