#include <Arduino.h>
//#include <DHT11.h>
#include <DHT.h>


extern DHT dht11;

/*
 *  Функция считывает значения температуры с датчика DHT11. Выполняет одно измерение.
 */
int Temperature(); 

/*
 *  Функция считывает значения влажности с датчика DHT11. Выполняет одно измерение.
 */
int Humidity(); 