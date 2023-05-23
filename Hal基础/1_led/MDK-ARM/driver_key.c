#include "driver_key.h"

uint8_t K1_Value(){
	if(K1 == 0){
		HAL_Delay(100);
		if(K1 ==0 )
			return 0;
	}
	return 1;
}