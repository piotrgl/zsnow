#ifndef __DRAW_SNAKE_H__
#define __DRAW_SNAKE_H__

#include "defines.h"

void draw_snake_segment_vertical(uint8_t x, uint8_t y);
void draw_snake_segment_horizontal(uint8_t x, uint8_t y);

void draw_snake_segment_turn_top_left(uint8_t x, uint8_t y);
void draw_snake_segment_turn_top_right(uint8_t x, uint8_t y);
void draw_snake_segment_turn_bottom_left(uint8_t x, uint8_t y);
void draw_snake_segment_turn_bottom_right(uint8_t x, uint8_t y);

#endif
