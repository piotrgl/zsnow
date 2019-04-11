#include "defines.h"
#include "field.h"
#include "draw_game_board.h"

struct Field game_board[GAME_BOARD_WIDTH][GAME_BOARD_HEIGHT];

void make_field_board_border_top(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_border_top;
}

void make_field_board_corner_top_left(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_corner_top_left;
}

void make_field_board_corner_top_right(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_corner_top_right;
}

void make_field_board_border_bottom(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_border_bottom;
}

void make_field_board_corner_bottom_left(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_corner_bottom_left;
}

void make_field_board_corner_bottom_right(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_corner_bottom_right;
}

void make_field_board_border_left(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_border_left;
}

void make_field_board_border_right(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_LETHAL;
    field->renderer = &draw_field_border_right;
}

void make_field_clear(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_EMPTY;
    field->renderer = &draw_field_empty;
}

void game_board_init(struct Field board[][GAME_BOARD_HEIGHT]) {
    for (uint8_t y = 0; y < GAME_BOARD_HEIGHT; y++) {
        for (uint8_t x = 0; x < GAME_BOARD_WIDTH; x++) {
            if ((y == 0) && (x == 0)) {
                make_field_board_corner_top_left(x, y, &board[x][y]);
            } else if ((y == 0) && (x == GAME_BOARD_WIDTH-1)) {
                make_field_board_corner_top_right(x, y, &board[x][y]);
            } else if (y == 0) {
                make_field_board_border_top(x, y, &board[x][y]);
            } else if ((y == GAME_BOARD_HEIGHT-1) && (x == 0)) {
                make_field_board_corner_bottom_left(x, y, &board[x][y]);
            } else if ((y == GAME_BOARD_HEIGHT-1) && (x == GAME_BOARD_WIDTH-1)) {
                make_field_board_corner_bottom_right(x, y, &board[x][y]);
            } else if (y == GAME_BOARD_HEIGHT-1) {
                make_field_board_border_bottom(x, y, &board[x][y]);
            } else if (x == 0) {
                make_field_board_border_left(x, y, &board[x][y]);
            } else if (x == GAME_BOARD_WIDTH-1) {
                make_field_board_border_right(x, y, &board[x][y]);
            }  else {
                make_field_clear(x, y, &board[x][y]);
            }
        }
    }
}

void game_board_render(struct Field board[][GAME_BOARD_HEIGHT]) {
    for (uint8_t y = 0; y < GAME_BOARD_HEIGHT; y++) {
        for (uint8_t x = 0; x < GAME_BOARD_WIDTH; x++) {
            render_field(&board[x][y]);
        }
    }
}
