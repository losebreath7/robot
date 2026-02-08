#include "time.h"
#include <GyverDS3231.h>
#include <Wire.h>

GyverDS3231 rtc;

void setup() 
{
    Serial.begin(115200);
    Serial.println("start");

    Wire.begin(21, 22);

    setStampZone(3);  // часовой пояс
    rtc.begin();

    Serial.print("OK: ");
    Serial.println(rtc.isOK());

    Serial.print("Reset: ");
    Serial.println(rtc.isReset());

    // был сброс питания RTC, время некорректное
    if (rtc.isReset()) {
        rtc.setBuildTime();  // установить время компиляции прошивки
        //rtc.setTime(2025, 1, 30, 12, 45, 0); // установить время вручную
    }
}

void loop() 
{
    // тикер вернёт true каждую секунду в 0 мс секунды, если время синхронизировано
    if (rtc.tick()) {
        // вывод даты и времени строкой
        Serial.print(rtc.toString());
    }
    Datime dt = rtc;
}