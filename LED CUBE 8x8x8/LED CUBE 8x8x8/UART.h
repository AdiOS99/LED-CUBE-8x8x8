/*
 * UART.h
 *
 * Created: 17.07.2018 20:24:17
 *  Author: AdiOS
 */ 



#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define FOSC 14745600
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1 

extern void USART_Init(unsigned int ubrr);
extern inline void transmit_led(bool a);


#endif /* TIMER_H_ */