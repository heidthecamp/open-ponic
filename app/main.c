// The main control loop for the aquaponic system

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

// #include "relay.h"
#include "lights.h"
#include "thermometer.h"
#include "pump.h"

// int relay_ids[RELAY_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7};


bool run_application();

void system_term();

// void handler(int signo, siginfo_t *info, void *context);
void handler(int signo);

// Initialize the system and return true if successful
bool system_init();

int main(int argc, char *argv[])
{
    bool shutdown = false;

    // SystemInit();
    shutdown = !system_init();
    
    int x = 0;
    float temp;
    while (!shutdown) {
        // Run the application
        shutdown = !run_application();
        // if(thermometer_get_temperature(&temp)){
        //     printf("Temp: %.2f C", temp);
        // }
    }

    system_term();
    // Return success
    return 0;
}

void handler(int signo)
{
    system_term();
    exit(EXIT_SUCCESS);
}

bool run_application()
{
    // remove this once the application is implemented
    static int index = 0;
    if (index >= 500) {
        return false;
    }

    lights_check();

    pipe_check_and_update();

    double temp;

    if (!thermometer_get_temperature(&temp)) {
        printf("The current temp is %.1lf C\n", temp);
    }
    else {
        printf("failed to get temp\n");
    }

    // Run the application
    ++index;
    return true;
}

// Initialize the system and return true if successful
bool system_init()
{
    printf("initializing the system\n");

    // printf("set exit conditions\n");
    // if (atexit(system_term) != 0){
    //     printf("could not handle atexit\n");
    //     exit(EXIT_FAILURE);
    // }

    printf("set event handler\n");
    signal(SIGINT, handler);

    printf("initialize subsystems\n");
    if (!lights_init()) {
        return false;
    }

    if (!thermometer_init()) {
        return false;
    }
    
    if (!pump_init()) {
        return false;
    }
    // next initialization ...


    printf("Successfully initialized\n");
    return true;
}

void system_term()
{
    printf("terminating the system\n");
    lights_term();
    thermometer_term();
    pump_term();
    // next termination ...
}