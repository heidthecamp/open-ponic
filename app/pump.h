// System to control pump for the aquaponic system
#ifndef PUMP_H
#define PUMP_H

// include relay to control pump
#include "relay.h"

// Function to turn on pump
void turnOnPump();

// Function to turn off pump
void turnOffPump();

// Function to get pump status
bool getPumpStatus();

// Function to set pump status
void setPumpStatus(bool status);

// Function to get pump schedule
char* getPumpSchedule();

// Function to set pump schedule
void setPumpSchedule(char* schedule);

// get waterlevel
float getWaterLevel();

#endif