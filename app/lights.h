// System to control lights for the aquaponic system
#ifndef LIGHTS_H
#define LIGHTS_H

// Include relay to control lights
#include "relay.h"
#include <stdbool.h>
#include <time.h>

// boolean array to store lights

bool lights_init();

bool lights_term();

bool lights_check();

// Functions to turn on lights
bool lights_all_on();
bool lights_on(int *lights, int size);
bool light_on(int light);

// Functions to turn off lights
bool lights_all_off();
bool lights_off(int *lights, int size);
bool light_off(int light);

// Function to get light status
// bool light_get_status();

#endif