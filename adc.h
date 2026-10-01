
/*
 * adc.h
 *
 * Created: 01/10/2026 23:06:59
 *  Author: Afeefa
 */ 
#ifndef ADC_H_
#define ADC_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>


void adc_init(void);
uint16_t read_adc(uint8_t channel);





#endif /* ADC_H_ */
