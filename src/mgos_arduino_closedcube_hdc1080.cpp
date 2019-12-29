#include "closedcube_hdc1080.h"

#include "mgos_arduino_closedcube_hdc1080.h"

class HDC1080_Sensor : public Sensor
{
public:
    HDC1080_Sensor()
    {
        sensor = ClosedCube_HDC1080();
        sensor.begin(0x40);
    }

    float readTemperature()
    {
        return sensor.readTemperature();
    }

    float readHumidity()
    {
        return sensor.readHumidity();
    }

    int readCO2()
    {
        return 0;
    }

    bool isAvailable()
    {
        uint16_t deviceID = this->getDeviceId();
        uint16_t manufacturerID = this->getManufacturerId();

        return (deviceID == 0x1050) && (manufacturerID == 0x5449);
    }

private:
    ClosedCube_HDC1080 sensor;
};

Sensor *mgos_HDC1080_create()
{
    return new HDC1080_Sensor();
}

bool mgos_HDC1080_is_available(Sensor *sensor)
{
    if (sensor == nullptr)
        return false;
    return sensor->isAvailable();
}

double mgos_HDC1080_read_temperature(Sensor *sensor)
{
    if (sensor == nullptr)
        return -1;
    return sensor->readTemperature();
}

double mgos_HDC1080_read_humidity(Sensor *sensor)
{
    if (sensor == nullptr)
        return -1;
    return sensor->readHumidity();
}
