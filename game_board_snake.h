#ifndef __GAME_BOARD_SNAKE_H__
#define __GAME_BOARD_SNAKE_H__

#include "defines.h"
#include "field.h"

void game_board_snake_init(uint8_t x, uint8_t y, struct Field board[][GAME_BOARD_HEIGHT]);
void make_snake_segment(struct Field *field, uint8_t curr_direction, uint8_t new_direction);

#endif
