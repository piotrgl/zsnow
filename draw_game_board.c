#include "defines.h"
#include "lcd.h"
#include "field.h"

void draw_field_border_left(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0xFF);
}

void draw_field_border_right(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH - 1; i++) {
        lcd_tx_data(0x00);
    }
    lcd_tx_data(0xFF);
}

void draw_field_border_top(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH; i++) {
        lcd_tx_data(0x01);
    }
}

void draw_field_border_bottom(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH; i++) {
        lcd_tx_data(0x80);
    }
}

void draw_field_corner_top_right(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH - 1; i++) {
        lcd_tx_data(0x01);
    }
    lcd_tx_data(0xFF);
}

void draw_field_corner_top_left(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0xFF);
    for (uint8_t i = 0; i < FIELD_WIDTH - 1; i++) {
        lcd_tx_data(0x01);
    }
}

void draw_field_corner_bottom_right(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH - 1; i++) {
        lcd_tx_data(0x80);
    }
    lcd_tx_data(0xFF);
}

void draw_field_corner_bottom_left(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0xFF);
    for (uint8_t i = 0; i < FIELD_WIDTH - 1; i++) {
        lcd_tx_data(0x80);
    }
}

void draw_field_empty(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    for (uint8_t i = 0; i < FIELD_WIDTH; i++) {
        lcd_tx_data(0x00);
    }
}

void draw_mouse(uint8_t x, uint8_t y) {
    lcd_goto_column(x*FIELD_WIDTH);
    lcd_goto_page(y);
    lcd_tx_data(0x00);
    lcd_tx_data(0x18);
    lcd_tx_data(0x3C);
    lcd_tx_data(0x7E);
    lcd_tx_data(0x7E);
    lcd_tx_data(0x3C);
    lcd_tx_data(0x18);
    lcd_tx_data(0x00);
}
