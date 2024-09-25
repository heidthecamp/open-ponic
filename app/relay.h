// system to control the relay for the aquaponic system

#ifndef RELAY_H
#define RELAY_H

// include raspberry pi gpio library
#include <stdbool.h>
#include "pin_io.h"

#define RELAY_COUNT 8

#define RELAY_ON LO
#define RELAY_OFF HI

bool relay_init();

bool relay_term();

bool relay_set(int pin, int value);

bool relay_get(int pin, int *value);

#endif

/*
wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install

===================

sudo ./x_pigpio # check C I/F

sudo pigpiod    # start daemon

./x_pigpiod_if2 # check C      I/F to daemon
./x_pigpio.py   # check Python I/F to daemon
./x_pigs        # check pigs   I/F to daemon
./x_pipe        # check pipe   I/F to daemon

*/