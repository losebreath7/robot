
#ifndef DUSTSENSOR_H
#define DUSTSENSOR_H

#include <Arduino.h>
#include <GP2YDustSensor.h>


bool DustSensorInit(void);

extern float dustDensity;

float DustSensorRead(void);


#endif // DUSTSENSOR_H
