#include "driver_key.h"

static volatile uint8_t key1_val = KEY_RELEASED;
static volatile uint8_t key2_val = KEY_RELEASED;

void KEY_GPIO_ReInit(void)
{
	KEY1_GPIO_CLK_EN();
	KEY2_GPIO_CLK_EN();
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	GPIO_InitStruct.Pin = K1_Pin|K2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	HAL_NVIC_SetPriority(EXTI15_10_IRQn,0,2);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(K1_Pin);
	HAL_GPIO_EXTI_IRQHandler(K2_Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == K1_Pin)
		key1_val = K1;
	if(GPIO_Pin == K2_Pin)
		key2_val = K2;	
}

uint8_t KEY1_Value(void)
{
	return key1_val;
}

uint8_t KEY2_Value(void)
{
	return key2_val;
}