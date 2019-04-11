#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <stdint.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define GAME_BOARD_HEIGHT 8
#define GAME_BOARD_WIDTH 16

#define SNAKE_START_SIZE 3
#define SNAKE_MAX_SIZE (GAME_BOARD_WIDTH-2)*(GAME_BOARD_HEIGHT-2)+1

#define START_CURR_DIRECTION RIGHT
#define START_NEW_DIRECTION RIGHT

#endif
