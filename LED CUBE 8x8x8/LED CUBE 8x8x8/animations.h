/*
 * animations.h
 *
 * Created: 26.07.2017 00:26:47
 *  Author: AdiOS
 */ 


#ifndef ANIMATIONS_H_
#define ANIMATIONS_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#define COUNT_OF_ANIMS 4

void anim1(void);	//parameters for animation functions are declared in variables below
void anim2(void);
void anim3(void);
void anim4(void);

extern void ( * anims[COUNT_OF_ANIMS])();

extern uint8_t anim, frame, layer, position, frame_repeats, anim_repeats;


#endif /* ANIMATIONS_H_ */