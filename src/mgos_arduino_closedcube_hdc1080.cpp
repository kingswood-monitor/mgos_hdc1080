#include "mgos_arduino_closedcube_hdc1080.h"

ClosedCube_HDC1080 *mgos_HDC1080_create()
{
    return new ClosedCube_HDC1080();
}

void mgos_HDC1080_begin(ClosedCube_HDC1080 *hdc)
{
    if (hdc == nullptr)
        return;
    hdc->begin(0x40);
}

uint16_t mgos_HDC1080_read_manufacturer_id(ClosedCube_HDC1080 *hdc)
{
    if (hdc == nullptr)
        return -1;
    uint16_t data = hdc->readManufacturerId();
    return data;
}

uint16_t mgos_HDC1080_read_device_id(ClosedCube_HDC1080 *hdc)
{
    if (hdc == nullptr)
        return -1;
    uint16_t data = hdc->readDeviceId();
    return data;
}

bool mgos_HDC1080_is_connected(ClosedCube_HDC1080 *hdc)
{
    if (hdc == nullptr)
        return -1;
    uint16_t deviceID = hdc->readDeviceId();
    uint16_t manufacturerID = hdc->readManufacturerId();

    return (deviceID == 0x1050) && (manufacturerID == 0x5449);
}

double mgos_HDC1080_read_temperature(ClosedCube_HDC1080 *hdc)
{
    if (hdc == nullptr)
        return -1;
    double data = hdc->readTemperature();
    return data;
}

double mgos_HDC1080_read_humidity(ClosedCube_HDC1080 *hdc)
{
    if (hdc == nullptr)
        return -1;
    double data = hdc->readHumidity();
    return data;
}
