#ifndef _DRIVER_KEY_H
#define _DRIVER_KEY_H

#include "stm32f1xx_hal.h"

#define KEY_PRESSED	(0)
#define KEY_RELEASED (1)

#define K1_Pin GPIO_PIN_14
#define K2_Pin GPIO_PIN_15

#define K1_GPIO_Port GPIOE
#define K2_GPIO_Port GPIOE

#define KEY1_GPIO_CLK_EN() __HAL_RCC_GPIOE_CLK_ENABLE()
#define KEY2_GPIO_CLK_EN() __HAL_RCC_GPIOE_CLK_ENABLE()

#define K1 HAL_GPIO_ReadPin(K1_GPIO_Port,K1_Pin)
#define K2 HAL_GPIO_ReadPin(K1_GPIO_Port,K2_Pin)

void KEY_GPIO_ReInit(void);
uint8_t KEY1_Value(void);
uint8_t KEY2_Value(void);
#endif
