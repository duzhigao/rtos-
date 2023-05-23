#include "driver_usart.h"
#include "stm32f1xx_hal.h"
#include "ring_buffer.h"
extern ring_buffer test_buffer;
extern UART_HandleTypeDef huart1;
static volatile uint8_t txcplt_flag = 0;
static volatile uint8_t rxcplt_flag = 0;

void EnableDebugIRQ(void)
{
	HAL_NVIC_SetPriority(USART1_IRQn,0,1);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
	
	__HAL_UART_ENABLE_IT(&huart1,UART_IT_TC | UART_IT_RXNE);
}
	
void DisableDebugIRQ(void)
{
	__HAL_UART_DISABLE_IT(&huart1,UART_IT_TC | UART_IT_RXNE);
	
	HAL_NVIC_DisableIRQ(USART1_IRQn);
}
int fgetc(FILE *file)
{
	rxcplt_flag = 0;
	unsigned char c = 0;
	while(ring_buffer_read(&c,&test_buffer) == -1);
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
	unsigned char c = 0;
	if(huart1.Instance->SR & (1<<5))
	{
		c = huart1.Instance->DR;
		ring_buffer_write(&test_buffer,c);
		
	}
	HAL_UART_IRQHandler(&huart1);
}



void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)
		txcplt_flag = 1;
}
