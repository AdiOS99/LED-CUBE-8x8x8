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

#define count_of_anims 4

uint8_t anim1(uint8_t frame, uint8_t layer, uint8_t position);
uint8_t anim2(uint8_t frame, uint8_t layer, uint8_t position);
uint8_t anim3(uint8_t frame, uint8_t layer, uint8_t position);
uint8_t anim4(uint8_t frame, uint8_t layer, uint8_t position);

extern uint8_t anim, frame, layer, position, frame_repeats, anim_repeats;


#endif /* ANIMATIONS_H_ */