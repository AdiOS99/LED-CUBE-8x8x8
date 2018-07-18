/*
 * UART.c
 *
 * Created: 17.07.2018 20:24:17
 *  Author: AdiOS
 */ 

 #include "UART.h"

 void USART_Init(unsigned int ubrr)
 {
	 DDRC=0xFF;
	 PORTC|=0x01;
	 /*Set baud rate*/
	 UBRRH = (unsigned char) (ubrr>>8);
	 UBRRL = (unsigned char) ubrr;
	 /*Enable receiver and transmitter*/
	 UCSRB = (1<<RXEN) | (1<<TXEN);
	 /*Set format: 8 data, 2 stop bits*/
	 UCSRC = (1<<URSEL) | (1<< USBS) | (3<<UCSZ0);
	 /*Enable receive and transmit interrupts*/
	 UCSRA = (1<<RXC) | (1<<TXC);
	 UCSRB |= (1<<RXCIE) | (1<<TXCIE);
	 PORTC^=0x01;
 }
 
 inline void transmit_led(bool a)
 {
	 if (a==1)
		PORTC|=0x01;
	else if (PORTC & 0x01)
		PORTC^=0x01;
		
 }
 
 ISR(USART_RXC_vect)
 {
	 transmit_led(true);
	 char ch=UDR;
	 
	 if(ch=='a')
		transmit_led(false);
	 
	 return;	
 }
 
 ISR(USART_TXC_vect)
 {
	 return;
 }
 
  ISR(USART_UDRE_vect)
  {
	  return;
  }