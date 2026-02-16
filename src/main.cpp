#include <Arduino.h>      
#include <SD.h> 
#include "dustsensor.h"
#include "time.h"
#include "temp_hum_sensor.h"
#include "dustsensor.h"
#include "sdd.h"
#include "gui.h"
#include "display.h"



void setup()
{
  Serial.begin(115200);
  delay(300);
    
    sd_init();
    delay(1000);

    DisplayInit();
    //delay(200);
    gui_init();

    dht11.begin();
    //2. датчик влажности и температуры 
   
    //3. Инициализация времени 
    RTC_Init(); 
    Serial.println(GetTime());  

    // функции инициализации RTC модуля
    DustSensorInit();
    //GetDustDensity();

    drawTime();
    //UpdateTime("19:11");

    drawHum(); 
    drawTemperature();
    drawDust();
   
}

void loop() {
  // put your main code here, to run repeatedly:
  //  Функция для обработки событий LVGL
  //  Должна вызываться в основном цикле программы
  
  process_gui(); 

  String timeHM = GetTimeHM();
  UpdateTime(timeHM.c_str());

  float humidity = dht11.readHumidity();
  float h = dht11.readHumidity();
  UpdateHum(h);

  float temperature = dht11.readTemperature();
  float t = dht11.readTemperature();
  updateTemperature(t);

  float d = DustSensorRead();     
  updateDust(d);
    
}