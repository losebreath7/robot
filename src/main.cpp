#include <Arduino.h>
#include "display.h"
#include "sd.h"
#include "dustsensor.h"
#include "time.h"
#include "temp_hum_sensor.h"

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);   
    //  функции инициализации дисплея 
    //  функции инициализации SD карты 
    //  функции инициализации датчика пыли        
}

void loop() {
  // put your main code here, to run repeatedly:
}

