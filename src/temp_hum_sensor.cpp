#include <Arduino.h>
#include "temp_hum_sensor.h"

DHT11 dht11(2);
/*  Функция считывает значения температуры с датчика DHT11. Выполняет одно измерение.
 *  возвращает true если данные успешно считаны, false если произошла ошибка чтения датчика
 */
int Temperature(void)
{
    // Попытка считать значения температуры с датчика DHT11. 
    int temperature = dht11.readTemperature();

    //Проверка результатов измерений.
    // Если измерение прошло успешно, вывести значения температуры.
    // Если возникли ошибки, вывести соответствующие сообщения об ошибках.
    if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT) {
        Serial.print("Температура: ");
        Serial.print(temperature);
        Serial.println(" °C");
        return temperature;
    } else {
        // Вывод ошибки
        Serial.println("Ошибка инициализации датчика температуры");
        return 0; // Возвращаем 0 или можно использовать другой код для обозначения ошибки
    }
}

/*  Функция считывает значения влажности с датчика DHT11. Выполняет одно измерение.
 *  возвращает true если данные успешно считаны, false если произошла ошибка чтения датчика
 */
int Humidity(void)
{
    // Попытка считать значения влажности с датчика DHT11.
    int humidity = dht11.readHumidity();

    //Проверка результатов измерений.
    // Если измерение прошло успешно, вывести значения влажности.
    // Если возникли ошибки, вывести соответствующие сообщения об ошибках.
    if (humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) {
        Serial.print("Влажность: ");
        Serial.print(humidity);
        Serial.println(" %");
        return humidity;
    } else {
        // Print error message based on the error code.
        Serial.println("Ошибка инициализации датчика влажности");
        return 0; // Возвращаем 0 или можно использовать другой код для обозначения ошибки
    }

}