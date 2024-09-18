// System for pH sensor

#ifndef PH_SENSOR_H
#define PH_SENSOR_H

// initialize the ph sensor
void ph_sensor_init();

float ph_sensor_read();

void set_ph_target(float target);

void set_ph_tolerance(float tolerance);

float get_ph_target();

float get_ph_tolerance();

#endif