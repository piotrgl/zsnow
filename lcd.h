#ifndef __LCD_H__
#define __LCD_H__

#include "defines.h"

void lcd_init();
void lcd_goto_column(uint8_t index);
void lcd_goto_page(uint8_t index);
void lcd_tx_data(uint8_t data);

#endif
