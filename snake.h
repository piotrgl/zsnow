#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "defines.h"

extern uint8_t curr_direction;
extern uint8_t new_direction;

void snake_init(uint8_t direction, uint8_t x, uint8_t y, struct Field board[][GAME_BOARD_HEIGHT]);
uint8_t move_snake(struct Field board[][GAME_BOARD_HEIGHT]);

#endif
