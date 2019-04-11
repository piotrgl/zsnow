#include "field.h"
#include "defines.h"
#include "draw_game_board.h"
#include "rand.h"

void make_field_mouse(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_FOOD;
    field->renderer = &draw_mouse;
}

void make_rand_mouse(struct Field board[][GAME_BOARD_HEIGHT]) {
    uint8_t x;
    uint8_t y;
    struct Field *field;
    while (1) {
        x = rand(1, 14);
        y = rand(1, 6);
        field = &board[x][y];
        if (is_field_empty(field)) break;
    }
    make_field_mouse(x, y, field);
    render_field(field);
}

void game_board_mouse_init(uint8_t x, uint8_t y, struct Field board[][GAME_BOARD_HEIGHT]) {
    make_field_mouse(x, y, &board[x][y]);
}
