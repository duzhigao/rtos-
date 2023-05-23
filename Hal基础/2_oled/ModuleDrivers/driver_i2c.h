#ifndef _DRIVER_I2C_H
#define _DRIVER_I2C_H

#include "stm32f1xx_hal.h"

#define SCL_Pin GPIO_PIN_10
#define SDA_Pin GPIO_PIN_11

#define SDA_GPIO_Port GPIOF
#define SCL_GPIO_Port GPIOF

/*主机对SCL电平操作*/
#define SCL_H HAL_GPIO_WritePin(SCL_GPIO_Port,SCL_Pin,1)
#define SCL_L HAL_GPIO_WritePin(SCL_GPIO_Port,SCL_Pin,0)
/*主机对SDA电平操作*/
#define SDA_H HAL_GPIO_WritePin(SDA_GPIO_Port,SDA_Pin,1)
#define SDA_L HAL_GPIO_WritePin(SDA_GPIO_Port,SDA_Pin,0)
/*主机读SDA电平*/
#define SDA_IN HAL_GPIO_ReadPin(SDA_GPIO_Port,SDA_Pin)


extern void I2C_Delay(uint32_t);
extern void I2C_GPIO_ReInit();
extern void I2C_Start();
extern void I2C_Stop();
extern int I2C_GetAck();
extern void I2C_ACK();
extern void I2C_NACK();

extern void I2C_WriteByte(uint8_t);
extern uint8_t I2C_ReadByte(uint8_t);


void OLED_PutChar(uint8_t page,uint8_t col,char c);
void OLED_PrintString(uint8_t page,uint8_t col,char * string);
#endif
