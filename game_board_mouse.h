#ifndef __GAME_BOARD_MOUSE_H__
#define __GAME_BOARD_MOUSE_H__

#include "defines.h"

void game_board_mouse_init(uint8_t x, uint8_t y, struct Field board[][GAME_BOARD_HEIGHT]);
void make_rand_mouse(struct Field board[][GAME_BOARD_HEIGHT]);

#endif
