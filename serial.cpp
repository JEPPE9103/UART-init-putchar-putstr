#include "serial.h"
#include <avr/io.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void uart_init() {
    /* Set baud rate */
    UBRR0H = (unsigned char)(MYUBRR >> 8);
    UBRR0L = (unsigned char)MYUBRR;
    /* Enable transmitter */
    UCSR0B = (1 << TXEN0);
    /* Set frame format: 8data, 1stop bit */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_putchar(char c) {
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)));
    /* Put data into buffer, sends the data */
    UDR0 = c;
}

void uart_putstr(const char *str) {
    while (*str) {
        uart_putchar(*str++);
    }
    uart_putchar('\n'); // Lägg till new line på slutet av strängen
}
