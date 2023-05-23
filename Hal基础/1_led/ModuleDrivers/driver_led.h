#ifndef _DRIVER_LED_H
#define _DRIVER_LED_H

#define BLUE_ON() HAL_GPIO_WritePin(GPIOF,BLUE_Pin,0)
#define BLUE_OFF() HAL_GPIO_WritePin(GPIOF,BLUE_Pin,1)
#define WHITE_ON() HAL_GPIO_WritePin(GPIOF,WHITE_Pin,0)
#define WHITE_OFF() HAL_GPIO_WritePin(GPIOF,WHITE_Pin,1)
#define GREEN_ON() HAL_GPIO_WritePin(GPIOF,GREEN_Pin,0)
#define GREEN_OFF() HAL_GPIO_WritePin(GPIOF,GREEN_Pin,1)

extern void Blue_On();
extern void Blue_Off();
extern void Blue_Shine();
extern void Blue_Shine2();
extern void Walter_Fall_Light();
extern void Marquee();
extern void Blue_Shine3();
#endif
	
