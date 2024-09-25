// The main control loop for the aquaponic system

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

#include "relay.h"
#include "thermometer.h"

int relay_ids[RELAY_COUNT] = {0, 1, 2, 3, 4, 5, 6, 7};


bool run_application()
{
    // remove this once the application is implemented
    static int index = 0;
    if (index >= 5) {
        return false;
    }

    // for (int i = 0; i < RELAY_COUNT; i++) {
    //     relay_set(i, RELAY_ON);
    // }

    // for (int i = 0; i < RELAY_COUNT; i++) {
    //     relay_set(i, RELAY_OFF);
    // }

    // Run the application
    ++index;
    return true;
}

void system_term()
{
    printf("terminating the system\n");
    // relay_term();

    // thermometer_term();
    // next termination ...
}

void handler(int signo, siginfo_t *info, void *context)
{
    printf("running handler\n");

    system_term();

    printf("ran terminate\n");

    fflush(stdout);

    struct sigaction oldact;

    if (sigaction(SIGSEGV, NULL, &oldact) == -1)
        // || (oldact.sa_flags & SA_UNSUPPORTED)
        // || !(oldact.sa_flags & SA_EXPOSE_TAGBITS))
    {
        _exit(EXIT_FAILURE);
    }
    _exit(EXIT_SUCCESS);
}

// Initialize the system and return true if successful
bool system_init()
{
    printf("initializing the system\n");

    printf("set exit conditions\n");
    if (atexit(system_term) != 0){
        printf("could not handle atexit\n");
        fflush(stdout);
        exit(EXIT_FAILURE);
    }

    printf("set event handler\n");
    struct sigaction act = { 0 };

    // act.sa_flags = SA_SIGINFO | SA_UNSUPPORTED | SA_EXPOSE_TAGBITS;
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = &handler;
    if (sigaction(SIGSEGV, &act, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("initialize subsystems\n");
    // if (!relay_init()) {
    //     return false;
    // }

    // if (!thermometer_init()) {
    //     return false;
    // }
    // next initialization ...


    printf("Successfully initialized\n");
    return true;
}

int main(int argc, char *argv[])
{
    printf("main\n");
    bool shutdown = false;

    // SystemInit();
    shutdown = !system_init();
    
    int x = 0;
    while (!shutdown) {
        // Run the application
        // shutdown = !run_application();
        if (x == 0) {
            printf("in the main loop\n");
        }
        if (x == 1) {
            raise(SIGSEGV);
        }
        ++x;
    }

    system_term();

    // Return success
    return 0;
}