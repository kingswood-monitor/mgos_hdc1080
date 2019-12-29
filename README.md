# Mongoose OS Library: TI HDC1080

## Overview

This is a library for a Texas Instruments HDC1080 low power, high accuracy digital temperature and humidity sensor. It is a port to Mongoose OS of the Arduino ClosedCube HDC1080 driver - ClosedCube's rights to the original code are acknowledged. It is configured in maximum (14 bit) resolution. It is tested on an ESP8266.

Interaction with the device is via a virtual interface. See [Mongoose OS Library: Sensor virtual interface](https://github.com/richardjlyon/arduino_sensor_interface) for details.

## Usage

### mos.yml

```
libs:
  - origin: https://github.com/richardjlyon/arduino_closedcube_hdc1080

config_schema:
  - ["i2c.enable", true]
  - ["i2c.scl_gpio", "i", 5, { title: "scl" }]
  - ["i2c.sda_gpio", "i", 4, { title: "sda" }]
```

### main.cpp

```
#include "mgos_arduino_closedcube_hdc1080.h"

// Create a sensor object
Sensor *sensor;

enum mgos_app_init_result mgos_app_init(void)
{
  // Initialise the sensor
  sensor = mgos_HDC1080_create();
  ...
}

timer_cb(void *)
{
  if (sensor->isAvailable())
  {
    double temp_c = sensor->readTemperature();
    double humidity = sensor->readHumidity();
  }
  ...
}
```
