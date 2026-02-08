#include "time.h"

GyverDS3231 rtc;
/*  Функция инициализрует время 
 *  возвращает true при успешной инициализации, false при ошибке шины или после сброса питания RTC 
 */
bool TimeInit(void)
{
    Serial.print("Инициализациия RTC модуля: ");
    setStampZone(3);  // часовой пояс
    if (rtc.begin()){
        Serial.println("Успешная инициализации RTC модуля");
        return true;
    } else {
        Serial.println("Ошибка инициализации RTC модуля");
        return false;
    }
}
