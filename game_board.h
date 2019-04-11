#ifndef __GAME_BOARD_H__
#define __GAME_BOARD_H__

#include "defines.h"
#include "field.h"

extern struct Field game_board[GAME_BOARD_WIDTH][GAME_BOARD_HEIGHT];

void game_board_init(struct Field board[][GAME_BOARD_HEIGHT]);
void game_board_render(struct Field board[][GAME_BOARD_HEIGHT]);
void make_field_clear(uint8_t x, uint8_t y, struct Field *field);

#endif
