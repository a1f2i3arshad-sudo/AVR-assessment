
/*
 * delay.c
 *
 * Created: 01/10/2026 23:09:53
 *  Author: Afeefa
 */ 
#include "delay.h"

void my_delay_ms(unsigned int ms)
{
	volatile unsigned long i,j;

	for(i=0;i<ms;i++)
	{
		for(j=0;j<1000;j++);
	}
}
