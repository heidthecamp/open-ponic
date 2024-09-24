// System to control pump for the aquaponic system
#ifndef PUMP_H
#define PUMP_H

// include relay to control pump
#include "relay.h"

void pump_init();

void pump_term();

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

#endif