#ifndef DUSTSENSOR_H
#define DUSTSENSOR_H

#include <GP2YDustSensor.h>

#define DUST_SENSOR_LED_PIN 25
#define DUST_SENSOR_VO_PIN 34

/*
 * Инициализация датчика пыли GP2Y1014AU0F.
 */
void DustSensorInit(void); 

/*
 * Получение плотности пыли в микрограммах на кубический метр.
 */
uint16_t GetDustDensity(void); 


/*
 * Получение скользящего среднего значения плотности пыли.
 */
uint16_t GetDustDensityRunningAverage(void); 


#endif // DUSTSENSOR_H
