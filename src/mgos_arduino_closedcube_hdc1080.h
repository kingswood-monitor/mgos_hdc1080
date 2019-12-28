/*
 * Arduido ClosedCube_HDC1080 Library API wrapper
 */

// #include "mgos.h"
#include "closedcube_hdc1080.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /*
    * Create an HDC1080 instance
    */

    ClosedCube_HDC1080 *mgos_HDC1080_create();

    /*
    * Initialise sensor
    */

    void mgos_HDC1080_begin(ClosedCube_HDC1080 *hdc);

    /*
     * Read manufacturer ID
     */

    uint16_t mgos_HDC1080_read_manufacturer_id(ClosedCube_HDC1080 *hdc);

    /*
     * Read device ID
     */

    uint16_t mgos_HDC1080_read_device_id(ClosedCube_HDC1080 *hdc);

    /*
     * Is device connected?
     */

    bool mgos_HDC1080_is_connected(ClosedCube_HDC1080 *hdc);

    /*
     * Read temperature
     */

    double mgos_HDC1080_read_temperature(ClosedCube_HDC1080 *hdc);

    /*
     * Read humidity
     */
    double mgos_HDC1080_read_humidity(ClosedCube_HDC1080 *hdc);

#ifdef __cplusplus
}
#endif /* __cplusplus */