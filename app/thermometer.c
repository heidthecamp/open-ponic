#include "thermometer.h"


sensors_chip_name scn;
const sensors_chip_name *p_chip;

bool thermometer_init()
{
    printf("Initializing thermometer\n");
    if (sensors_init(NULL) != 0){
        return false;
    }

    // const char * chip_name = sensors_get_detected_chips("w1_slave_temp-virtual-0", NULL);
    // printf("%s\n", chip_name);
    
    // https://stackoverflow.com/questions/8556551/has-anyone-been-able-to-use-libsensors-properly
    sensors_chip_name const *chip_name;
    int c = 0;

    char *cn = "w1_slave_temp-*";

    // the following allocates memory and requires it to be freed call sensors_free_chip_name before closing
    if (sensors_parse_chip_name(cn, &scn) != 0) {
        printf("err: could not get chip name\n");
        sensors_free_chip_name(&scn);
        return false;
    }

    int nr = 0;
    p_chip = sensors_get_detected_chips(&scn, &nr);

    if (!p_chip) {
        printf("err: could not detect chip\n");
        sensors_free_chip_name(&scn);
        return false;
    }

    return true;
}

void thermometer_term()
{
    printf("Terminating thermometer\n");
    sensors_free_chip_name(&scn);
    sensors_cleanup();
}

bool thermometer_get_temperature(double *temperature)
{
    if (sensors_get_value(p_chip, 0, temperature) != 0) {
        printf("could not get value\n");
        return false;
    }
    printf("this should return a temp of %.1lf C\n", temperature);

    return true;
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