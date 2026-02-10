// https://www.espboards.dev/sensors/gp2y1010au0f/#arduino      

#include "dustsensor.h"

GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1014AU0F, DUST_SENSOR_LED_PIN, DUST_SENSOR_VO_PIN);


/*
 * Инициализация датчика пыли GP2Y1014AU0F.
 */
void DustSensorInit(void)
{
    dustSensor.begin();
}

/*
 * Получение плотности пыли в микрограммах на кубический метр.
 */
uint16_t GetDustDensity(void)
{    return dustSensor.getDustDensity();
}

/*
 * Получение скользящего среднего значения плотности пыли.
 */
uint16_t GetDustDensityRunningAverage(void)
{    return dustSensor.getRunningAverage();
}
