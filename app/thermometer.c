#include "thermometer.h"

bool thermometer_init()
{
    if (sensors_init(NULL) != 0){
        return false;
    }

    // const char * chip_name = sensors_get_detected_chips("w1_slave_temp-virtual-0", NULL);
    // printf("%s\n", chip_name);

    return true;
}

void thermometer_term()
{
    sensors_cleanup();

}

bool thermometer_get_temperature(float *temperature)
{
    return false;
}

bool thermometer_set_target_temperature(float temperature)
{
    return false;
}

bool thermometer_set_temperature_alert_threshold(float low, float high)
{
    return false;
}

bool thermometer_get_temperature_alert_threshold(float *low, float *high)
{
    return false;
}

bool thermometer_check_temperature_alert_status()
{
    return false;
}

char* thermometer_get_temperature_alert_message()
{
    
}