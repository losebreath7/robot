
// https://www.espboards.dev/sensors/gp2y1010au0f/#arduino      
#include <Arduino.h>
#include "dustsensor.h"

const uint8_t SHARP_LED_PIN = 25;
const uint8_t SHARP_VO_PIN  = 34;

GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1010AU0F, SHARP_LED_PIN, SHARP_VO_PIN);

bool sensorInitialized = false;
float dustDensity = -1.0f;

bool DustSensorInit(void)
{
  Serial.println("Инициализация датчика пыли...");
  dustSensor.begin();
  sensorInitialized = true;
  Serial.println("Датчик пыли успешно инициализирован");
  return true;
}

float DustSensorRead(void)
{
  if (!sensorInitialized) {
    Serial.println("Ошибка инициализации датчика пыли");
    dustDensity = -1.0f;
    return dustDensity;
  }

  float raw = (float)dustSensor.getDustDensity();
  dustDensity = raw / 1.667f;

  if (dustDensity < 0.0f || dustDensity > 2000.0f) {
    Serial.print("Значение уровня пыли выходит за пределы допустимого диапазона: ");
    Serial.println(dustDensity);
  } else {
    Serial.print("Пыль: ");
    Serial.print(dustDensity);
    Serial.println(" мг/м3");
  }

  return dustDensity;
}


/*
 * Получение скользящего среднего значения плотности пыли.
 */
uint16_t GetDustDensityRunningAverage(void)
{    return dustSensor.getRunningAverage();
}
