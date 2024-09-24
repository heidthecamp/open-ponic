// system to control/monitor the thermometer for the aquaponic system
#ifndef THERMOMETER_H
#define THERMOMETER_H

// initialize the thermometer
bool thermometer_init();

void thermometer_term();

// get the temperature from the thermometer
bool thermometer_get_temperature(float *temperature);

// set the temperature of the thermometer
bool thermometer_set_target_temperature(float temperature);

// set temperature alert threshold
bool thermometer_set_temperature_alert_threshold(float low, float high);

// get temperature alert threshold
bool thermometer_get_temperature_alert_threshold(float *low, float *high);

// get temperature alert status
bool thermometer_check_temperature_alert_status();

// get temperature alert message
char* thermometer_get_temperature_alert_message();

# endif