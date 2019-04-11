#include "defines.h"
#include "rand.h"
#include "uart.h"
#include "buttons.h"
#include "delays.h"
#include "spi.h"
#include "lcd.h"
#include "game_board.h"
#include "game_board_mouse.h"
#include "game_board_snake.h"
#include "snake.h"

void restart_game() {
    game_board_init(game_board);
    game_board_mouse_init(8, 3, game_board);
    game_board_snake_init(1, 1, game_board);
    snake_init(RIGHT, 1, 1, game_board);
    game_board_render(game_board);
}

void main() {
    //unsigned char c;

    rand_init();
    uart_init();
    buttons_init();
    spi_init();
    lcd_init();

    uart_puts("greetings!");

    restart_game();

    while(1) {
        wait_usec_st(500000);
        if (button_up_event_detected()) {
            button_up_event_clear();
            new_direction = UP;
        }
        if (button_down_event_detected()) {
            button_down_event_clear();
            new_direction = DOWN;
        }
        if (button_left_event_detected()) {
            button_left_event_clear();
            new_direction = LEFT;
        }
        if (button_right_event_detected()) {
            button_right_event_clear();
            new_direction = RIGHT;
        }
        if (move_snake(game_board) != 0) {
            restart_game();
        }
    }
}

