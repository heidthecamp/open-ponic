#ifndef pin_io_h
#define pin_io_h

#include <stdbool.h>
#include <pigpio.h>

#define HI 1
#define LO 0

bool pin_io_init();
void pin_io_term();

bool pin_io_set(int pin, int value);
bool pin_io_get(int pin, int *value);

bool pin_io_set_mode(int pin, int mode);

#endif // pin_io_h
