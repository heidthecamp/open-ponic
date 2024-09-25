// The main control loop for the aquaponic system

#include <stdlib.h>
#include <stdbool.h>
#include "relay.h"

int relay_ids[RELAY_COUNT] = {-1};


bool run_application()
{
    // remove this once the application is implemented
    static int index = 0;
    if (index >= 10) {
        return false;
    }

    for (int i = 0; i < RELAY_COUNT; i++) {
        relay_set(i, 1);
    }

    for (int i = 0; i < RELAY_COUNT; i++) {
        relay_set(i, 0);
    }

    // Run the application
    ++index;
    return true;
}

// Initialize the system and return true if successful
bool system_init()
{
    if (!relay_init()) {
        return false;
    }
    for (int i = 0; i < RELAY_COUNT; i++) {
        if (!relay_request_pin(i)) {
            return false;
        }
        relay_ids[i] = i;
    }

    // next initialization ...

    return true;
}

void system_term()
{
    for (int i = 0; i < RELAY_COUNT; i++) {
        if (relay_ids[i] >= 0) {
            relay_release_pin(i);
        }
    }
    relay_term();

    // next termination ...
}

int main(int argc, char *argv[])
{
    bool shutdown = false;

    // SystemInit();
    shutdown = !system_init();
    
    while (!shutdown) {
        // Run the application
        shutdown = !run_application();
    }

    system_term();

    // Return success
    return 0;
}