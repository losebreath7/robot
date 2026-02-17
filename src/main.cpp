#include <Arduino.h>      
#include <SD.h> 
#include "dustsensor.h"
#include "time.h"
#include "temp_hum_sensor.h"
#include "dustsensor.h"
#include "sdd.h"
#include "gui.h"
#include "display.h"

// Тайминги
static const uint32_t GUI_PERIOD_MS   = 5;       // дисплей
static const uint32_t SENS_PERIOD_MS  = 1000;    // датчики
static const uint32_t SD_PERIOD_MS    = 5000;    // запись на SD 

static uint32_t tSens = 0;
static uint32_t tSd   = 0;

static int lastT = 0;
static int lastH = 0;
static float lastDust = 0;

void setup()
{
    Serial.begin(115200);
    delay(200);
    
    // Инициализация SD-карты
    if (!sd_init()) {
        Serial.println("Ошибка при инициализации SD-карты");
    }

    // Инициализация дисплея 
    DisplayInit();
    gui_init();

    // Инициализация RTC модуля
    RTC_Init();

    // Инициализация датчика температуры и влажности
    dht11.begin();

    // Инициализация датчика пыли
    DustSensorInit();

    // Отображение на дисплее
    drawTime();
    drawHum();
    drawTemperature();
    drawDust();

    // Первое обновление сразу
    tSens = millis();
    tSd = millis();
}

void loop()
{
    process_gui();

    uint32_t now = millis();

    // Обновление датчиков 
    if (now - tSens >= SENS_PERIOD_MS) {
        tSens = now;

        String hm = GetTimeHM();
        UpdateTime(hm.c_str());

        lastH = (int)dht11.readHumidity();
        lastT = (int)dht11.readTemperature();

        lastDust = DustSensorRead();

        UpdateHum(lastH);
        updateTemperature((float)lastT);
        updateDust(lastDust);
    }

    // Запись на SD 
    if (now - tSd >= SD_PERIOD_MS) {
        tSd = now;

        String hm = GetTimeHM();
        bool ok = data_recording(hm.c_str(), lastT, lastH, lastDust);
        Serial.print("Запись на SD-карту = ");
        Serial.println(ok ? "успешно" : "неуспешно");
    }
}
