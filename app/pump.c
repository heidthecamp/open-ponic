#include "pump.h"

#define pump_relay_id 4
#define DURATION 10

int pipes[] = {5, 6, 7};
int open_pipe = -1;
time_t next_pipe;

bool pump_init() {
    if (!relay_init) {
        return false;
    }

    pump_turn_on();
    return true;
}

bool pump_term(){
    pump_turn_off();
    return relay_term();
}

// Function to turn on pump
void pump_turn_on(){
    relay_set(pump_relay_id, RELAY_ON);
}

// Function to turn off pump
void pump_turn_off(){
    relay_set(pump_relay_id, RELAY_OFF);
}

bool pipe_init() {
    // set update time
    time(&next_pipe);

    return false;
}

bool pipe_check_and_update() {
    if (time(NULL) >= next_pipe) {
        next_pipe = time(NULL) + (10 * 60); // min * seconds current time plus 10 minutes
        
        int num_pipes = sizeof(pipes) / sizeof(pipes[0]);

        open_pipe = (open_pipe + 1) % num_pipes;
        int value;
        for( int i = 0; i < num_pipes; ++i) {
            if (i == 0) {
                value = RELAY_ON;
            } else {
                value = RELAY_OFF;
            }

            if (!relay_set(pipes[(i + open_pipe) % num_pipes], value)) {
                return false;
            }
        }
    }
    return true;
}

// Function to get pump status
// bool pump_get_pump();

// Function to get pump schedule
// char* pump_get_schedule();

// Function to set pump schedule
// void pump_set_schedule(char* schedule);

// get waterlevel
// float pump_get_water_level();