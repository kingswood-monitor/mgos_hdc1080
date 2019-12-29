# Mongoose OS Driver: HDC1080

## Overview

This is a driver for a Texas Instruments HDC1080 low power, high accuracy digital temperature and humidity sensor. It is a port to Mongoose OS of the Arduino ClosedCube HDC1080 driver - ClosedCube's rights to the original code are acknowledged. It is configured in maximum (14 bit) resolution. It is tested on an ESP8266.

## Usage

### mos.yml

```
libs:
  - origin: https://github.com/richardjlyon/arduino_closedcube_hdc1080.git

config_schema:
  - ["i2c.enable", true]
  - ["i2c.scl_gpio", "i", 5, { title: "scl" }]
  - ["i2c.sda_gpio", "i", 4, { title: "sda" }]
```

### main.cpp

```
#include "mgos_arduino_closedcube_hdc1080.h"

ClosedCube_HDC1080 *hdc1080 = mgos_HDC1080_create();

enum mgos_app_init_result mgos_app_init(void)
{
  // Initialise the sensor
  mgos_HDC1080_begin(hdc1080);
  ...
}

timer_cb(void *)
{
  if (mgos_HDC1080_is_connected(hdc1080))
  {
    double temp_c = mgos_HDC1080_read_temperature(hdc1080);
    double humidity = mgos_HDC1080_read_humidity(hdc1080);
  }
  ...
}
```
