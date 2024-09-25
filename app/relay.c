#include "relay.h"
#include <unistd.h>

const int SLEEP_TIME_MS = 250;

int pin_ids[RELAY_COUNT];

#define ON 1
#define OFF 0

bool relay_init()
{
    bool success = true;
    success = pin_io_init();
    // Initialize the relay

    if (!success) {
        return false;
    }

    for (int i = 0; i < RELAY_COUNT; i++) {
        pin_ids[i] = pin_io_add();
    }

    return true;
}

bool relay_term()
{
    pin_io_term();
    // Terminate the relay
    return true;
}

bool relay_set(int pin, int value)
{
    if (pin < 0 || pin >= RELAY_COUNT) {
        return false;
    }

    pin_io_set(pin_ids[pin], !value);
    return true;
}

int relay_get_RELAY_COUNT()
{
    return RELAY_COUNT;
}

// set the value of the relay
// This will sleep for 250ms to allow the relay to switch and avoid shorting
bool relay_set(int pin, int value)
{
    if (pin < 0 || pin >= RELAY_COUNT) {
        return false;
    }

    if (!pin_assigned[pin]) {
        return false;
    }

    pin_io_set(pin_ids[pin], value = ON);
    usleep(SLEEP_TIME_MS * 1000);
    return true;
}

bool relay_get(int pin, bool *value)
{
    if (pin < 0 || pin >= RELAY_COUNT) {
        return false;
    }

    if (!pin_assigned[pin]) {
        return false;
    }

    pin_io_get(pin_ids[pin], value);
    return true;
}
