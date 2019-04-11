#include "defines.h"
#include "gpio.h"
#include "spi.h"
#include "delays.h"

#define LCD_RST_BIT_N 25
#define LCD_CMD_DATA_BIT_N 24

#define COLUMN_COUNT 0x84
#define PAGE_COUNT 0x08

#define CMD_GOTO_PAGE 0xB0
#define CMD_GOTO_COLUMN_HI 0x10
#define CMD_GOTO_COLUMN_LO 0x00

void configure_lcd_pins() {
    *GPFSEL2 |= 0b001 << 12; //GPIO24 output (nCommand/data)
    *GPFSEL2 |= 0b001 << 15; //GPIO25 outpusendt nRst
}

void lcd_tx_data(uint8_t data) {
    *GPSET0 = 1 << LCD_CMD_DATA_BIT_N;
    spi_tx_byte(data);
}

void lcd_tx_cmd(uint8_t cmd) {
    *GPCLR0 = 1 << LCD_CMD_DATA_BIT_N;
    spi_tx_byte(cmd);
}

void lcd_reset_on() {
    *GPCLR0 = 1 << LCD_RST_BIT_N;
}

void lcd_reset_off() {
    *GPSET0 = 1 << LCD_RST_BIT_N;
}

void lcd_goto_page(uint8_t index) {
    lcd_tx_cmd((index & 0x0F) | CMD_GOTO_PAGE);
}

void lcd_goto_column(uint8_t index) {
    lcd_tx_cmd(((index >> 4) & 0x0F) | CMD_GOTO_COLUMN_HI);
    lcd_tx_cmd((index & 0x0F) | CMD_GOTO_COLUMN_LO);
}

void lcd_clear() {
    for (int i=0; i<PAGE_COUNT; i++) {
        lcd_goto_page(i);
        lcd_goto_column(0);
        for (int j=0; j<COLUMN_COUNT; j++) {
            lcd_tx_data(0x00);
        }
    }
}

void lcd_init() {
    configure_lcd_pins();
    spi_enable();
    lcd_reset_on();
    wait_usec_st(500000);
    lcd_reset_off();

    lcd_tx_cmd(0xA3);
    lcd_tx_cmd(0xA0);
    lcd_tx_cmd(0xC8);
    lcd_tx_cmd(0x40);
    lcd_tx_cmd(0x28|0x04);
    wait_usec_st(50000);
    lcd_tx_cmd(0x28|0x6);
    wait_usec_st(50000);
    lcd_tx_cmd(0x28|0x7);
    wait_usec_st(10000);

    lcd_tx_cmd(0x20|0x07);

    //set brightness
    lcd_tx_cmd(0x81); // volume first
    lcd_tx_cmd(0x00 & 0x3f); // volume second

    lcd_clear();
    lcd_goto_page(0);
    lcd_goto_column(0);

    // display on
    lcd_tx_cmd(0xAF);
    // all pts normal
    lcd_tx_cmd(0xA4);

    spi_disable();
}
