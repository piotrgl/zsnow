#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include "defines.h"

void buttons_init();

uint8_t button_up_event_detected();
void button_up_event_clear();
uint8_t button_left_event_detected();
void button_left_event_clear();
uint8_t button_down_event_detected();
void button_down_event_clear();
uint8_t button_right_event_detected();
void button_right_event_clear();

#endif
