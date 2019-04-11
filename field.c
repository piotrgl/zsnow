#include "field.h"

void render_field(struct Field *field) {
    field->renderer(field->x, field->y);
}

uint8_t is_field_empty(struct Field *field) {
    return field->properties & FIELD_PROP_EMPTY;
}

uint8_t is_field_lethal(struct Field *field) {
    return field->properties & FIELD_PROP_LETHAL;
}

uint8_t is_field_snake(struct Field *field) {
    return field->properties & FIELD_PROP_SNAKE;
}

uint8_t is_field_food(struct Field *field) {
    return field->properties & FIELD_PROP_FOOD;
}
