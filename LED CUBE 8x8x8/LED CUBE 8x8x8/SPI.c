/*
 * SPI_master.c
 *
 * Created: 26.07.2017 00:27:41
 *  Author: AdiOS
 */ 

#include "SPI.h"
#include "animations.h"

/*Enable SPI in master mode with interrupts*/
void SPI_master_init(void)
{
	DDRB |= _BV(PB5) | _BV(PB7) | _BV(PB4);		//MOSI, SCK, SS are outputs
	SPI_set_SS_line(0);
	SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPIE);		//Enable SPI, Master, Interrupts
	SPSR;
	SPDR;	//Delete SPIF Flag
}

/*For the SPI: low on the SS line is ON, high is OFF	*/
void SPI_set_SS_line(const bool x)	//	For x:
{										//		0 - nothing is sending by SPI
	if (x==0){							//		1 - set SS line
		PORTB|=_BV(PB4);				
	}else if (x==1){
		PORTB&=~(_BV(PB4));
	}
	asm volatile ("nop");
}


ISR(SPI_STC_vect)
{
	SPI_set_SS_line(0);
	if (position>=9)
	{
		layer++;
	}else
	{
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
	}
	position++;

}



