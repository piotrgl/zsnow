#include "defines.h"
#include "field.h"
#include "game_board_mouse.h"
#include "game_board_snake.h"
#include "game_board.h"

uint8_t curr_direction;
uint8_t new_direction;

static struct Field * snake[SNAKE_MAX_SIZE];
static struct Field ** snake_buf_start;
static struct Field ** snake_buf_end;
static struct Field ** snake_tail;
static struct Field ** snake_head;

void snake_init(uint8_t direction, uint8_t x, uint8_t y, struct Field board[][GAME_BOARD_HEIGHT]) {
    curr_direction = direction;
    new_direction = direction;

    for (uint8_t i = 0; i < SNAKE_START_SIZE; i++) {
        snake[i] = &board[x+i][y];
    }
    snake_buf_start = &snake[0];
    snake_buf_end = &snake[0+SNAKE_MAX_SIZE-1];
    snake_tail = &snake[0];
    snake_head = &snake[SNAKE_START_SIZE-1];
}

void update_direction() {
    // Ignore invalid moves (in exact opposite direction)
    if (curr_direction == RIGHT && new_direction == LEFT) {
        new_direction = RIGHT;
    } else if (curr_direction == LEFT && new_direction == RIGHT) {
        new_direction = LEFT;
    } else if (curr_direction == UP && new_direction == DOWN) {
        new_direction = UP;
    } else if (curr_direction == DOWN && new_direction == UP) {
        new_direction = DOWN;
    } else {
        curr_direction = new_direction;
    }
}

struct Field *get_new_snake_head_segment(struct Field board[][GAME_BOARD_HEIGHT], uint8_t direction) {
    uint8_t curr_x = (*snake_head)->x;
    uint8_t curr_y = (*snake_head)->y;

    switch (direction) {
        case LEFT:
            return &board[curr_x-1][curr_y];
        case RIGHT:
            return &board[curr_x+1][curr_y];
        case UP:
            return &board[curr_x][curr_y-1];
        case DOWN:
            return &board[curr_x][curr_y+1];
    }
    return 0;
}

void advance_snake_ptr(struct Field ***ptr) {
    if (*ptr == snake_buf_end) {
        *ptr = snake_buf_start;
    } else {
        (*ptr)++;
    }
}

uint8_t move_snake(struct Field board[][GAME_BOARD_HEIGHT]) {
    struct Field *field;
    uint8_t grow = 0;

    field = get_new_snake_head_segment(board, curr_direction);
    if (is_field_lethal(field)) return 1;
    if (is_field_snake(field)) return 1;
    if (is_field_food(field)) {
        grow = 1;
        make_rand_mouse(board);
    }

    make_snake_segment(field, curr_direction, new_direction);
    advance_snake_ptr(&snake_head);
    *snake_head = field;
    render_field(field);

    update_direction();

    if (grow) {
        return 0;
    } else {
        field = *snake_tail;
        make_field_clear(field->x, field->y, field);
        render_field(field);
        advance_snake_ptr(&snake_tail);
    }
    return 0;
}
