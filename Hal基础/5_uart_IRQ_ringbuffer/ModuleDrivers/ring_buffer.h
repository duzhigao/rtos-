#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H

#include "stm32f1xx_hal.h"

#define BUFFER_SIZE 1024
typedef struct
{
	unsigned char buffer[BUFFER_SIZE];
	volatile unsigned int pW;
	volatile unsigned int pR;
	
}ring_buffer;

void ring_buffer_init(ring_buffer *dst_buf);
void ring_buffer_write(ring_buffer *dst_buf,unsigned char c);
int ring_buffer_read(unsigned char *c,ring_buffer *dst_buf);
#endif