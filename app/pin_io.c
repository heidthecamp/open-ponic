#include "pin_io.h"

// Number of pins on the raspberry pi 3
const int NUM_PINS = 30;

// initialize the 30 pins on the raspberry pi 3
bool pin_assigned[NUM_PINS] = {false};

bool initialized = false;

bool pin_io_init() {
    if (initialized) {
        return true;
    }
    
    if (gpioInitialise() < 0) {
        return false;
    }

    initialized = true;
    return true;
;
}

bool pin_io_term() {
    gpioTerminate();
    return true;
}

bool pin_io_set(int pin, bool value) {
    gpioWrite(pin, value);
    return true;
}

bool pin_io_get(int pin, bool *value) {
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

