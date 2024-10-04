#include "pin_io.h"

// Number of pins on the raspberry pi 3
bool initialized = false;

bool pin_io_init() {
    if (initialized) {
        printf("Pin io already initialized\n");
        return true;
    }
    
    if (gpioInitialise() < 0) {
        return false;
    }

    initialized = true;
    return true;
}

void pin_io_term() {
    gpioTerminate();
}

bool pin_io_set(int pin, int value) {
    gpioWrite(pin, value);
    return true;
}

bool pin_io_get(int pin, int *value) {
    *value = gpioRead(pin);
    return true;
}

bool pin_io_set_mode(int pin, int mode) {
    gpioSetMode(pin, mode);
    return true;
}

