#include "lights.h"


int relay_ids[] = {0, 1, 2, 3};


// assuming on_at is less than off_at
int on_at;
int off_at;

bool lights_init()
{
    if (!relay_init()) {
        return false;
    }

    on_at   = 8; // 8:00 AM
    off_at  = 18; // 6:00 PM

    return true;
}

bool lights_term()
{
    relay_term();
}

bool lights_check()
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    int hour = timeinfo->tm_hour;
    
    int light_status;    

    if (on_at < hour && hour < off_at) {
        light_status = RELAY_ON;
    } else {
        light_status = RELAY_OFF;
    }
    for (int i = 0; i < (sizeof(relay_ids) / sizeof(relay_ids[0])); ++i) {
        if (!relay_set(relay_ids[i], light_status)) {
            return false;
        }
    }
    // // printf ( "Current local time and date: %s", asctime (timeinfo) );
    return true;
}

// Functions to turn on lights
bool lights_all_on()
{
    for (int i = 0; i < sizeof(relay_ids); ++i) {
        if (!relay_set(relay_ids[i], RELAY_ON)) {
            return false;
        }
    }
    return true;
}

bool lights_on(int *lights, int size)
{
    for ( int i = 0; i < size; ++i) {
        if (!relay_set(relay_ids[lights[i]], RELAY_ON)) {
            return false;
        }
    }
    return true;
}

bool light_on(int light)
{
    return relay_set(relay_ids[light], RELAY_ON);
}

// Functions to turn off lights
bool lights_all_off()
{
    for (int i = 0; i < sizeof(relay_ids); ++i) {
        if (!relay_set(relay_ids[i], RELAY_OFF)) {
            return false;
        }
    }
    return true;
}

bool lights_off(int *lights, int size)
{
    for ( int i = 0; i < size; ++i) {
        if (!relay_set(relay_ids[lights[i]], RELAY_OFF)) {
            return false;
        }
    }
    return true;

}

bool light_off(int light)
{
    return relay_set(relay_ids[light], RELAY_OFF);
}

// Function to get light status
// bool light_get_status()
// {
//     relay_get()
// }
