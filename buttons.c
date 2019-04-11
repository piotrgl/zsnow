#include "defines.h"
#include "gpio.h"

#define BUTTONS_GPFSEL          GPFSEL0
#define BUTTON_DOWN_GPFBIT      6   // GPIO02
#define BUTTON_LEFT_GPFBIT      9   // GPIO03
#define BUTTON_UP_GPFBIT        12  // GPIO04
#define BUTTON_RIGHT_GPFBIT     15  // GPIO05

#define BUTTON_DOWN_GPENBIT     2
#define BUTTON_LEFT_GPENBIT     3
#define BUTTON_UP_GPENBIT       4
#define BUTTON_RIGHT_GPENBIT    5

#define BUTTON_DOWN_EDS_BIT     2
#define BUTTON_LEFT_EDS_BIT     3
#define BUTTON_UP_EDS_BIT       4
#define BUTTON_RIGHT_EDS_BIT    5

void buttons_init() {
    // gpio as input
    *BUTTONS_GPFSEL &= ~(0b111 << BUTTON_UP_GPFBIT);
    *BUTTONS_GPFSEL &= ~(0b111 << BUTTON_DOWN_GPFBIT);
    *BUTTONS_GPFSEL &= ~(0b111 << BUTTON_LEFT_GPFBIT);
    *BUTTONS_GPFSEL &= ~(0b111 << BUTTON_RIGHT_GPFBIT);
    // enable gpio falling edge sync detect
    *GPFEN0 |= 1 << BUTTON_DOWN_GPENBIT;
    *GPFEN0 |= 1 << BUTTON_LEFT_GPENBIT;
    *GPFEN0 |= 1 << BUTTON_UP_GPENBIT;
    *GPFEN0 |= 1 << BUTTON_RIGHT_GPENBIT;
}

uint8_t button_up_event_detected() {
    return *GPEDS0 & (1 << BUTTON_UP_EDS_BIT);
}

void button_up_event_clear() {
    *GPEDS0 |= 1 << BUTTON_UP_EDS_BIT;
}

uint8_t button_left_event_detected() {
    return *GPEDS0 & (1 << BUTTON_LEFT_EDS_BIT);
}

void button_left_event_clear() {
    *GPEDS0 |= 1 << BUTTON_LEFT_EDS_BIT;
}

uint8_t button_down_event_detected() {
    return *GPEDS0 & (1 << BUTTON_DOWN_EDS_BIT);
}

void button_down_event_clear() {
    *GPEDS0 |= 1 << BUTTON_DOWN_EDS_BIT;
}

uint8_t button_right_event_detected() {
    return *GPEDS0 & (1 << BUTTON_RIGHT_EDS_BIT);
}

void button_right_event_clear() {
    *GPEDS0 |= 1 << BUTTON_RIGHT_EDS_BIT;
}
