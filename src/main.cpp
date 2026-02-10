#include <Arduino.h>      
#include "display.h"
#include "sd.h"
#include "dustsensor.h"
#include "time.h"
#include "temp_hum_sensor.h"
#include "dustsensor.h"
#include "gui.h"

void setup(){
  // put your setup code here, to run once:
    Serial.begin(115200);
      
    //1. графический интерфейс 
    gui_init();

    //2. датчик влажности и температуры 
    Temperature(); 
    Humidity();

    //3. Инициализация времени 
    RTC_Init(); 
    Serial.println( GetTime() );  
    
    // функции инициализации RTC модуля
  
}

void loop() {
  // put your main code here, to run repeatedly:
  process_gui(); 
}
