// system to control/monitor the thermometer for the aquaponic system
#ifndef THERMOMETER_H
#define THERMOMETER_H

// initialize the thermometer
void initThermometer();

// get the temperature from the thermometer
float getTemperature();

// set the temperature of the thermometer
void setTemperature(float temperature);

// set temperature alert threshold
void setTemperatureAlertThreshold(float threshold);

// get temperature alert threshold
float getTemperatureAlertThreshold();

// get temperature alert status
bool getTemperatureAlertStatus();

// set temperature alert status
void setTemperatureAlertStatus(bool status);

// get temperature alert message
char* getTemperatureAlertMessage();

// set temperature alert message
void setTemperatureAlertMessage(char* message);

# endif