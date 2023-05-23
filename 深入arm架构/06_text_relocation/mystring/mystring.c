#include "mystring.h"

void my_memcpy(void *des,void *source,unsigned int size)
{
	unsigned char *pDes;
	unsigned char *pSource;
	while(size--)
	{
		*pDes = *pSource;
		pDes++;
		pSource++;
		
	}
}


void my_memset(void *des,char c,unsigned int size)
{
	unsigned char *pDes;
	while(size--)
	{
		*pDes = c;
		pDes++;
	}
}




