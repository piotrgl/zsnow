#ifndef __DRAW_GAME_BOARD_H__
#define __DRAW_GAME_BOARD_H__

#include "defines.h"

void draw_field_border_left(uint8_t x, uint8_t y);
void draw_field_border_right(uint8_t x, uint8_t y);
void draw_field_border_top(uint8_t x, uint8_t y);
void draw_field_border_bottom(uint8_t x, uint8_t y);

void draw_field_corner_top_right(uint8_t x, uint8_t y);
void draw_field_corner_top_left(uint8_t x, uint8_t y);
void draw_field_corner_bottom_right(uint8_t x, uint8_t y);
void draw_field_corner_bottom_left(uint8_t x, uint8_t y);

void draw_field_empty(uint8_t x, uint8_t y);

void draw_mouse(uint8_t x, uint8_t y);

#endif
