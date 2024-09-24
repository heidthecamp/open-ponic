#include "pin_io.h"

// Number of pins on the raspberry pi 3
const int NUM_PINS = 30;

// initialize the 30 pins on the raspberry pi 3
bool *pin_states[NUM_PINS];
bool pin_assigned[NUM_PINS] = {0};

bool pin_io_init() {
    pin_state = calloc(NUM_PINS, sizeof(bool));
    if (gpioInitialise() < 0) {
        return false;
    }
    return true;
}

bool pin_io_term() {
    gpioTerminate();
    free(pin_states);
    return true;
}

bool pin_io_set(int pin, int value) {
    gpioWrite(pin, value);
    return true;
}

bool pin_io_get(int pin, int *value) {
    *value = gpioRead(pin);
    return true;
}

int pin_io_add() {
    return gpioInitialise();
}

bool pin_io_remove(int pin) {
    gpioTerminate();
    return true;
}

bool pin_io_set_mode(int pin, int mode) {
    gpioSetMode(pin, mode);
    return true;
}

bool pin_io_get_mode(int pin, int *mode) {
    *mode = gpioGetMode(pin);
    return true;
}

