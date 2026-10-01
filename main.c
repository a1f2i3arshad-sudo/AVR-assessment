
/*
 * main.c
 *
 * Created: 20/09/2026 13:33:58
 *  Author: Afeefa
 */ 
#define F_CPU 16000000UL
#include<avr/io.h>
#include "adc.h"
#include "lcd.h"
#include "uart.h"
#include "led.h"
#include "delay.h"



int main(void)
{
	//char buffer[16];
	float temperature;   // store temperature value from adc
	uint16_t adc_value;
	adc_init();
	lcd_init();
	UART_init();
	led_init();
	lcd_set_cursor(0, 0);   // setting lcd 1st line
	lcd_print("Temperature");

	
	while (1)
	{
		
		adc_value=read_adc(0);
		temperature= adc_value*0.488;  // converting adc value to celecius scale
		
		lcd_set_cursor(1, 0);
		lcd_print_float(temperature);  // temperature display on lcd
		
		
		
		UART_TxString("Temperature : ");  // serial monitor display
		UART_TXFloat(temperature);
		UART_TxString("\r\n");
		led_toggle();
		my_delay_ms(500);
		
		
		
	}
}
