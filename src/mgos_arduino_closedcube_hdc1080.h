/*
 * Arduido ClosedCube_HDC1080 Library API wrapper
 */

#include "sensor.h"

extern "C"
{
    // Create an HDC1080 instance
    Sensor *mgos_HDC1080_create();

    // Read manufacturer ID
    uint16_t mgos_HDC1080_read_manufacturer_id(Sensor *sensor);

    // Read device ID
    uint16_t mgos_HDC1080_read_device_id(Sensor *sensor);

    // Is device connected?
    bool mgos_HDC1080_is_available(Sensor *sensor);

    // Read temperature
    double mgos_HDC1080_read_temperature(Sensor *sensor);

    // Read humidity
    double mgos_HDC1080_read_humidity(Sensor *sensor);
}