#include "relay.h"
#include <unistd.h>

const int SLEEP_TIME_MS = 250;

int pin_ids[RELAY_COUNT];

bool relay_init()
{
    printf("Initializing relay\n");
    // Initialize the relay
    if (!pin_io_init()) {
        return false;
    }

    for (int i = 0; i < RELAY_COUNT; i++) {
        pin_ids[i] = i + 2;
    }

    return true;
}

bool relay_term()
{
    printf("Terminating Relay\n");
    relay_all_off();
    pin_io_term();
    // Terminate the relay
    return true;
}

// set the value of the relay
// This will sleep for 250ms to allow the relay to switch and avoid shorting
bool relay_set(int pin, int value)
{
    if (pin < 0 || pin >= RELAY_COUNT) {
        return false;
    }

    pin_io_set(pin_ids[pin], value);
    usleep(SLEEP_TIME_MS * 1000);
    return true;
}

bool relay_get(int pin, int *value)
{
    if (pin < 0 || pin >= RELAY_COUNT) {
        return false;
    }

    bool tmp;
    pin_io_get(pin_ids[pin], value);
    return true;
}

bool relay_all_off()
{
    for (int i = 0; i < RELAY_COUNT; ++i) {
        if (!pin_io_set(pin_ids[i], RELAY_OFF)){
            return false;
        }
    }
    return true;
}