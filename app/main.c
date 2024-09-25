// The main control loop for the aquaponic system

#include <stdlib.h>
#include <stdbool.h>
#include "relay.h"

int relay_ids[RELAY_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7};


bool run_application()
{
    // remove this once the application is implemented
    static int index = 0;
    if (index >= 10) {
        return false;
    }

    for (int i = 0; i < RELAY_COUNT; i++) {
        relay_set(i, RELAY_ON);
    }

    for (int i = 0; i < RELAY_COUNT; i++) {
        relay_set(i, RELAY_OFF);
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


    // next initialization ...

    return true;
}

void system_term()
{
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