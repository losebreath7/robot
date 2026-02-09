#include "time.h"

String time_getString();
RTC_DS3231 rtc;         // Создаем объект для работы с RTC

/*  Функция инициализрует время 
 *  возвращает true при успешной инициализации, false при ошибке шины или после сброса питания RTC 
 */
bool RTC_Init(void)
{
    Serial.print("Инициализациия RTC модуля: ");

    if (rtc.begin()){
        Serial.println("Успешная инициализации RTC модуля");
        return true;
    } else {
        Serial.println("Ошибка инициализации RTC модуля");
        return false;
    }
}
/*  Функция возвращает текущее время в виде строки
 *  Формат: YYYY-MM-DD HH:MM:SS
 */
String time_getString(void)
{
    DateTime now = rtc.now();

    char buf[25];
    snprintf(
        buf, sizeof(buf),
        "%04d-%02d-%02d %02d:%02d:%02d",
        now.year(), now.month(), now.day(),
        now.hour(), now.minute(), now.second()
    );

    return String(buf);
}