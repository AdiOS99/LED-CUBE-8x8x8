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
	position=0;
	if (layer>=8)
	{
		layer=0;
		frame_repeats++;
		if (frame_repeats>=frame_in_anim_repeats[anim])
		{
			frame++;
			if (frame==anims_frames[anim])
			{
				frame=0;
				anim_repeats++;
				if (anim_repeats==anims_repeats[anim])
				{
					anim_repeats=0;
					anim=anim%count_of_anims+1;

				}
			}
			frame_repeats=0;
		}
	}
	
		
	SPI_set_SS_line(1);
	switch(anim)
	{
		case 1:
			SPDR=anim1[frame][layer][position];
			break;
		case 2:
			SPDR=anim2[frame][layer][position];
			break;
		case 3:
			SPDR=anim3[frame][layer][position];
			break;
		case 4:
			SPDR=anim4[frame][layer][position];
			break;
		case 5:
			SPDR=anim5[frame][layer][position];
			break;

	}
	position++;
}

