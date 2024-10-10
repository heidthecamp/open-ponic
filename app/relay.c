#include "relay.h"
#include <unistd.h>

// 1/4 second sleep time to prevent shorting
const int SLEEP_TIME_MS = 250;

// This is the pin order that best matches the gpio pins
int pin_ids[RELAY_COUNT] = {2, 3, 4, 9, 8, 7, 5, 6};

bool relay_initialized = false;

bool relay_init()
{
    if (relay_initialized) {
        return true;
    }
    printf("Initializing relay\n");
    // Initialize the relay
    if (!pin_io_init()) {
        return false;
    }

    relay_initialized = true;
    return true;
}

bool relay_term()
{
    if (!relay_initialized) {
        return true;
    }
    printf("Terminating Relay\n");
    relay_all_off();
    pin_io_term();
    // Terminate the relay
    relay_initialized = false;
    return true;
}

// set the value of the relay
// This will sleep for 250ms to allow the relay to switch and avoid shorting
bool relay_set(int relay_id, int value)
{
    int check;
    if (!relay_get(relay_id, &check)) {
        return false;
    }
    if (check == value) {
        return true;
    }
    if (!relay_initialized) {
        printf("Attempted to set relay without initilizing\n");
        return false;
    }
    if (relay_id < 0 || relay_id >= RELAY_COUNT) {
        return false;
    }

    pin_io_set(pin_ids[relay_id], value);
    usleep(SLEEP_TIME_MS * 1000);
    return true;
}

bool relay_get(int relay_id, int *value)
{
    if (!relay_initialized) {
        printf("Attempted to get relay without initilizing\n");
        return false;
    }
    if (relay_id < 0 || relay_id >= RELAY_COUNT) {
        return false;
    }

    bool tmp;
    pin_io_get(pin_ids[relay_id], value);
    return true;
}

bool relay_all_off()
{
    if (!relay_initialized) {
        printf("Attempted to set relay without initilizing\n");
        return false;
    }
    for (int i = 0; i < RELAY_COUNT; ++i) {
        if (!pin_io_set(pin_ids[i], RELAY_OFF)){
            return false;
        }
    }
    return true;
}