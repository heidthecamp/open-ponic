// System to control pump for the aquaponic system
#ifndef PUMP_H
#define PUMP_H

#include <time.h>
#include "relay.h"

bool pump_init();

bool pump_term();

// Function to turn on pump
void pump_turn_on();

// Function to turn off pump
void pump_turn_off();

// Function to get pump status
bool pump_get_pump();

// Function to get pump schedule
char* pump_get_schedule();

// Function to set pump schedule
void pump_set_schedule(char* schedule);

// get waterlevel
float pump_get_water_level();

bool pipe_init();

bool pipe_check_and_update();

#endif