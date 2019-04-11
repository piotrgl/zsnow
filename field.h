#ifndef __FIELD_H__
#define __FIELD_H__

#include "defines.h"

#define FIELD_WIDTH 8 // num of pixels per field

#define FIELD_PROP_EMPTY    0x01
#define FIELD_PROP_LETHAL   0x02
#define FIELD_PROP_FOOD     0x04
#define FIELD_PROP_SNAKE    0x08

struct Field {
    uint8_t x;
    uint8_t y;
    uint8_t properties;
    void (*renderer)(uint8_t x, uint8_t y);
} Field;

void render_field(struct Field *field);

uint8_t is_field_empty(struct Field *field);
uint8_t is_field_lethal(struct Field *field);
uint8_t is_field_snake(struct Field *field);
uint8_t is_field_food(struct Field *field);

#endif
