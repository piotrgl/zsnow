#include "defines.h"
#include "lcd.h"
#include "field.h"

void draw_snake_segment_vertical(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH; i++) {
        if (i == 3)
            lcd_tx_data(0xFF);
        else
            lcd_tx_data(0x00);
    }
}

void draw_snake_segment_horizontal(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH; i++) {
        lcd_tx_data(0x08);
    }
}

void draw_snake_segment_turn_top_left(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0x0F);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
}

void draw_snake_segment_turn_top_right(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0x0F);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
}

void draw_snake_segment_turn_bottom_left(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0xF8);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
}

void draw_snake_segment_turn_bottom_right(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0x00);
    lcd_tx_data(0xF8);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
    lcd_tx_data(0x08);
}
