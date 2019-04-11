#include "field.h"
#include "defines.h"
#include "draw_snake.h"

void make_snake_segment_horizontal(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_SNAKE;
    field->renderer = &draw_snake_segment_horizontal;
}

void make_snake_segment_vertical(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_SNAKE;
    field->renderer = &draw_snake_segment_vertical;
}

void make_snake_segment_turn_bottom_left(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_SNAKE;
    field->renderer = &draw_snake_segment_turn_bottom_left;
}

void make_snake_segment_turn_top_left(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_SNAKE;
    field->renderer = &draw_snake_segment_turn_top_left;
}

void make_snake_segment_turn_bottom_right(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_SNAKE;
    field->renderer = &draw_snake_segment_turn_bottom_right;
}

void make_snake_segment_turn_top_right(uint8_t x, uint8_t y, struct Field *field) {
    field->x = x;
    field->y = y;
    field->properties = FIELD_PROP_SNAKE;
    field->renderer = &draw_snake_segment_turn_top_right;
}

void make_snake_segment(struct Field *field, uint8_t curr_dir, uint8_t new_dir) {
    switch (curr_dir) {
        case LEFT:
            switch (new_dir) {
                case LEFT:
                    make_snake_segment_horizontal(field->x, field->y, field);
                    break;
                case RIGHT:
                    make_snake_segment_horizontal(field->x, field->y, field);
                    break;
                case UP:
                    make_snake_segment_turn_top_right(field->x, field->y, field);
                    break;
                case DOWN:
                    make_snake_segment_turn_bottom_right(field->x, field->y, field);
                    break;
            }
            break;
        case RIGHT:
            switch (new_dir) {
                case LEFT:
                    make_snake_segment_horizontal(field->x, field->y, field);
                    break;
                case RIGHT:
                    make_snake_segment_horizontal(field->x, field->y, field);
                    break;
                case UP:
                    make_snake_segment_turn_top_left(field->x, field->y, field);
                    break;
                case DOWN:
                    make_snake_segment_turn_bottom_left(field->x, field->y, field);
                    break;
            }
            break;
        case UP:
            switch (new_dir) {
                case LEFT:
                    make_snake_segment_turn_bottom_left(field->x, field->y, field);
                    break;
                case RIGHT:
                    make_snake_segment_turn_bottom_right(field->x, field->y, field);
                    break;
                case UP:
                    make_snake_segment_vertical(field->x, field->y, field);
                    break;
                case DOWN:
                    make_snake_segment_vertical(field->x, field->y, field);
                    break;
            }
            break;
        case DOWN:
            switch (new_dir) {
                case LEFT:
                    make_snake_segment_turn_top_left(field->x, field->y, field);
                    break;
                case RIGHT:
                    make_snake_segment_turn_top_right(field->x, field->y, field);
                    break;
                case UP:
                    make_snake_segment_vertical(field->x, field->y, field);
                    break;
                case DOWN:
                    make_snake_segment_vertical(field->x, field->y, field);
                    break;
            }
            break;
    }
}

void game_board_snake_init(uint8_t x, uint8_t y, struct Field board[][GAME_BOARD_HEIGHT]) {
    struct Field *field;
    for (uint8_t i = 0; i < SNAKE_START_SIZE; i++) {
        field = &board[x+i][y];
        make_snake_segment_horizontal(field->x, field->y, field);
    }
}
