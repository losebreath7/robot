#include <Arduino.h>      
#include "display.h"
#include <sd.h> 
#include "dustsensor.h"
#include "time.h"
#include "temp_hum_sensor.h"
#include "dustsensor.h"
#include "gui.h"



void setup()
{
  Serial.begin(115200);
    gui_init();
    DisplayInit(); 
    
    dht11.begin();
    //2. датчик влажности и температуры 
   
    //3. Инициализация времени 
    RTC_Init(); 
    Serial.println( GetTime() );  

    // функции инициализации RTC модуля

    drawTime();
    UpdateTime("02:11");

    drawHum(); 
    drawTemperature();

    //int temperature, humidity = 0;
    //int result = dht11.readTemperatureHumidity(temperature, humidity);
    
    
   
}

void loop() {
  // put your main code here, to run repeatedly:
  //  Функция для обработки событий LVGL
  //  Должна вызываться в основном цикле программы
  process_gui(); 

  float humidity = dht11.readHumidity();
    float h = dht11.readHumidity();
    UpdateHum(h);

    float temperature = dht11.readTemperature();
    float t = dht11.readTemperature();
    updateTemperature(t);
}