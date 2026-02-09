#include <Arduino.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>
#include "temp_hum_sensor.h"
#include "time.h"

#define CS_PIN 5

bool sd_init();
bool sd_append();
bool data_recording();
