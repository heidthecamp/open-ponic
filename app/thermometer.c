#include "thermometer.h"

sensors_chip_name name;
const sensors_chip_name *p_chip;

bool thermometer_init()
{
    printf("Initializing thermometer\n");
    if (sensors_init(NULL) != 0){
        return false;
    }

    // const char * chip_name = sensors_get_detected_chips("w1_slave_temp-virtual-0", NULL);
    // printf("%s\n", chip_name);
    
    printf("creating temp chip pointer\n");
    sensors_chip_name const *chip_name;
    int c = 0;
    // while ((chip_name = sensors_get_detected_chips(0, &c)) != 0) {
    //     printf("Chip: %s / %s\n", chip_name->prefix, chip_name->path);

    //     sensors_feature const *feat;
    //     int f = 0;

    //     while ((feat = sensors_get_features(chip_name, &f)) != 0) {
    //         printf("%d: %s\n", f, feat->name);

    //         sensors_subfeature const *subf;
    //         int s = 0;

    //         while ((subf = sensors_get_all_subfeatures(chip_name, feat, &s)) != 0) {
    //             printf("%d : %d : %s / %d\n", f, s, subf->name, subf->number);
    //             double val;
    //             if (subf->flags & SENSORS_MODE_R) {
    //                 int rc = sensors_get_value(chip_name, subf->number, &val);
    //                 if (rc < 0) {
    //                     printf("err: %d\n", rc);
    //                 } else {
    //                     printf("val: %d\n", val);
    //                 }
    //             }
    //         }
    //     }
    // }

    char *cn = "w1_slave_temp-*";

    printf("prasing %s\n", cn);

    if (sensors_parse_chip_name(cn, &name) != 0) {
        printf("err: could not get chip name\n");
        sensors_free_chip_name(&name);
        return false;
    }

    int nr = 0;
    p_chip = sensors_get_detected_chips(&name, &nr);

    if (!p_chip) {
        printf("err: could not detect chip\n");
        sensors_free_chip_name(&name);
        return false;
    }

    printf("chip: %s\n", p_chip->prefix);

    sensors_free_chip_name(&name);

    return true;
}

void thermometer_term()
{
    sensors_chip_name(p_chip)
    printf("Terminating thermometer\n");
    sensors_cleanup();
}

bool thermometer_get_temperature(double *temperature)
{   
    if (sensors_get_value(p_chip, 0, temperature) != 0) {
        printf("could not get value\n");
        return false;
    }

    // printf("%.2f", temperature);
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