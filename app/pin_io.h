#ifndef pin_io_h
#define pin_io_h

#include <stdbool.h>
#include <pigpio.h>

bool pin_io_init();
bool pin_io_term();

bool pin_io_set(int pin, int value);
bool pin_io_get(int pin, int *value);

int pin_io_add();
bool pin_io_remove(int pin);

bool pin_io_set_mode(int pin, int mode);
bool pin_io_get_mode(int pin, int *mode);

#endif // pin_io_h
