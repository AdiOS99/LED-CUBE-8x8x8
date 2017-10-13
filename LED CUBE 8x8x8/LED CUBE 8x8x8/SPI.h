/*
 * SPI_master.h
 *
 * Created: 26.07.2017 00:27:25
 *  Author: AdiOS
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

void SPI_master_init(void);
void SPI_set_SS_line(const bool);




#endif /* SPI_H_ */

