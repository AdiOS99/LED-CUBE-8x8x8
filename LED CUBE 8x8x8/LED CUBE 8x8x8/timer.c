/*
 * timer.c
 *
 * Created: 26.07.2017 23:35:06
 *  Author: AdiOS
 */ 

#include "timer.h"
#include "SPI.h"
#include "animations.h"

void timer_init(void)
{
	TCCR1B=_BV(WGM12) | (_BV(CS12)|_BV(CS10)) ;		//Set timer1 to the CTC mode with TOP described in OCR1A, prescaler=1024
	OCR1A=0x0006;									//Set frequency of changing layers on the cube: 14745600/6(OCR1A)*1024=>2400/8=300Hz
	TIMSK=_BV(OCIE1A);								//Enable compare match Interrupts
}

ISR(TIMER1_COMPA_vect)
{
	anims[anim]();
}

