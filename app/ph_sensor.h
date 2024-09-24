// System for pH sensor

#ifndef PH_SENSOR_H
#define PH_SENSOR_H

// initialize the ph sensor
void ph_sensor_init();

void ph_sensor_term();

float ph_sensor_read();

void ph_set_target(float target);

void ph_set_tolerance(float tolerance);

float ph_get_target();

float ph_get_tolerance();

#endif