
/*
 * adc.c
 *
 * Created: 01/10/2026 23:03:36
 *  Author: Afeefa
 */ 
#include "adc.h"
#include <avr/io.h>


void adc_init(void)
{
	// step1: setting the reference voltage , AVcc
	ADMUX |= (1<<REFS0);
	// step2: ADC Enable
	ADCSRA |= (1<<ADEN);
	// Step3: Choosing the prescalar value : 128 ~ 125kHz
	ADCSRA |= ((1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2));	
}

/*to read adc value from the corresponding given channel (0 -7)*/
uint16_t read_adc(uint8_t channel)
{
	/*step4: limit the choosen channel b/w 0 - 7
	-channel limit is 0 -7 (0000 _0111)
	-if choose 8 ==1000  ie; beyond our limit
	-channel = 8(1000)
	-channel & 0x07= 0000 1000 & 0000 0111 == 0000 0000
	-so automatically channel is selected as 0 ie;  with in our limit
	*/
	channel &= 0x07;
	// step 5:  to clear the previous channel and update the register with the new channel
	ADMUX = (ADMUX & 0xF0) | channel;
	//step6: to start the adc conversion 
	ADCSRA |= (1<<ADSC);
	// step7: wait until the conversion is done or completed
	while(ADCSRA & (1<<ADSC));
	// step8 : return adc 
	return ADC;
	
}
	