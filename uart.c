
/*
 * uart.c
 *
 * Created: 01/10/2026 23:25:21
 *  Author: Afeefa
 */ 
#include "uart.h"

void UART_init(void)
{
	/*Loading the baud rate to the UBRROH and UBRROL Registers*/
	UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
	UBRR0L = (unsigned char)UBRR_VALUE;
	
	UCSR0B = (1 << TXEN0);                      // Enable transmitter
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);     // 8-bit data
}
/*Uart function to print the character*/
void UART_TxChar(char data)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}
/*UART function to print the string*/
void UART_TxString(const char *str)
{
	while (*str)
	{
		UART_TxChar(*str++);
	}
}

/*Uart function to print the hex value*/
void UART_TxHex(uint8_t value)
{
	const char hexChars[] = "0123456789ABCDEF";
	char hex[5];
	hex[0] = hexChars[(value >> 4) & 0x0F];
	hex[1] = hexChars[value & 0x0F];
	hex[2] = '\r';
	hex[3] = '\n';
	hex[4] = '\0';
	UART_TxString("0x");
	UART_TxString(hex);
}
/*UART function to print the numbers*/
void UART_TxNumber(uint32_t num)
{
	char buffer[12];
	ltoa(num, buffer, 10);   // convert to string (long to ASCII)
	UART_TxString(buffer);
}

void UART_TXFloat(float value)
{
	if (value < 0)
	{
		UART_TxString("-");
		value= -value;
	}
	
	// integer part
	uint32_t int_part = (uint32_t)value;
	UART_TxNumber(int_part);
	UART_TxString(".");
	
	// fractional part
	float frac = value - int_part;
	frac = frac*100.0f;
	uint32_t frac_part = (uint32_t)(frac+0.5f);
	
	if(frac_part < 10)
	UART_TxString("0");
	UART_TxNumber(frac_part);
}

