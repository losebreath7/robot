#ifndef TIME_H
#define TIME_H

#include <Wire.h>              // Подключаем библиотеку для I2C связи
#include <Arduino.h>    
#include <RTClib.h>            // Подключаем библиотеку для работы с DS3231 RTC

extern RTC_DS3231 rtc;         // Создаем объект для работы с RTC

/*  Функция инициализрует время 
 *  возвращает true при успешной инициализации, false при ошибке шины или после сброса питания RTC 
 */
bool RTC_Init(void);
String time_getString(void);

#endif  // TIM_H