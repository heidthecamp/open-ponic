// System to control lights for the aquaponic system
#ifndef LIGHTS_H
#define LIGHTS_H

// Include relay to control lights
#include "relay.h"
#include <stdbool.h>

// boolean array to store lights

bool lights_init();

bool lights_term();

bool light_add(int light);

bool light_remove(int light);

// Functions to turn on lights
bool lights_all_on();
bool lights_on(int *lights, int size);
bool light_on(int light);

// Functions to turn off lights
bool lights_all_off();
bool lights_off(int *lights, int size);
bool light_off(int light);

// Function to get light status
bool light_get_status();

// Function to set light status
void light_set_status(bool status);


// ====== STRETCH GOALS ====== //

// Function to get light schedule
// char* getLightSchedule();

// Function to set light schedule
// void setLightSchedule(char* schedule);

// Function to get light intensity
// Function to set light intensity

#endif