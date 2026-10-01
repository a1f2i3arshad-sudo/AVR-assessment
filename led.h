
/*
 * led.h
 *
 * Created: 01/10/2026 23:11:01
 *  Author: Afeefa
 */ 
#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

#define LED_PIN PD0

void led_init(void);
void led_toggle(void);


#endif /* LED_H_ */
