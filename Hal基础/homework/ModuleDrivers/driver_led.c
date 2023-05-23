#include "main.h"
#include "driver_led.h"
void Blue_On(){
	HAL_GPIO_WritePin(GPIOF,BLUE_Pin,0);
}

void Blue_Off(){
	HAL_GPIO_WritePin(GPIOF,BLUE_Pin,1);
}

void Blue_Shine(){
	Blue_On();
	HAL_Delay(500);
	Blue_Off();
	HAL_Delay(500);
}

void Blue_Shine2(){
	HAL_GPIO_TogglePin(GPIOF,BLUE_Pin);
	HAL_Delay(200);
}

void Blue_Shine3(){
	HAL_GPIO_TogglePin(GPIOF,BLUE_Pin);
}

void Walter_Fall_Light(){
	WHITE_ON();
	HAL_Delay(300);
	BLUE_ON();
	HAL_Delay(300);
	GREEN_ON();
	HAL_Delay(300);
	WHITE_OFF();
	HAL_Delay(300);
	BLUE_OFF();
	HAL_Delay(300);
	GREEN_OFF();
	HAL_Delay(300);
}

void Marquee(){
	WHITE_ON();
	HAL_Delay(300);
	WHITE_OFF();
	BLUE_ON();
	HAL_Delay(300);
	BLUE_OFF();
	GREEN_ON();
	HAL_Delay(300);
	GREEN_OFF();
}