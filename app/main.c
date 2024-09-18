// The main control loop for the aquaponic system

#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    bool shutdown = false;

    // // Initialize the system
    // SystemInit();
    // // Initialize the peripherals
    // SystemCoreClockUpdate();
    // // Initialize the peripherals
    // InitializePeripherals();
    // // Initialize the application
    // InitializeApplication();
    
    while (!shutdown) {
        // Run the application
        RunApplication();
    }

    // Return success
    return 0;
}