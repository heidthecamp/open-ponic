// System to control lights for the aquaponic system
#ifndef LIGHTS_H
#define LIGHTS_H

// Include relay to control lights
#include "relay.h"
#include <stdbool.h>

// Function to turn on lights
void turnOnLights();

// Function to turn off lights
void turnOffLights();

// Function to get light status
bool getLightStatus();

// Function to set light status
void setLightStatus(bool status);


// ====== STRETCH GOALS ====== //

// Function to get light schedule
// char* getLightSchedule();

// Function to set light schedule
// void setLightSchedule(char* schedule);

// Function to get light intensity
// Function to set light intensity

#endif