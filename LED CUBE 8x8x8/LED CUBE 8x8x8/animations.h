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

const extern uint8_t __flash anim1[10][8][9];
const extern uint8_t __flash anim2[19][8][9];
const extern uint8_t __flash anim3[55][8][9];
const extern uint8_t __flash anim4[51][8][9];
const extern uint8_t __flash anim5[14][8][9];
extern uint8_t anim, frame, layer, position, frame_repeats, anim_repeats;
extern const uint8_t anims_frames[count_of_anims+1];
extern const uint8_t frame_in_anim_repeats[count_of_anims+1];
extern const uint8_t anims_repeats[count_of_anims+1];

#endif /* ANIMATIONS_H_ */