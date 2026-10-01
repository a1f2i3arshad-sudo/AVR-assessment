
/*
 * led.c
 *
 * Created: 01/10/2026 23:12:00
 *  Author: Afeefa
 */ 
#include <avr/io.h>
#include "led.h"

void led_init(void)
{
	DDRD |= (1<<LED_PIN);
}

void led_toggle(void)
{
	PORTD ^=(1 << LED_PIN);
}
