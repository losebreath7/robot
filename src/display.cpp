#include "display.h"

// Пины CS
#define SD_CS  5
#define TFT_CS 26

TFT_eSPI tft = TFT_eSPI();  // СОЗДАЕМ ОБЬЕКТ, ПИНЫ ОПРЕДЕЛНЫ В User_Setup.h

void DisplayInit(void)
{
    pinMode(TFT_CS, OUTPUT);
    pinMode(SD_CS, OUTPUT);
    digitalWrite(TFT_CS, HIGH);
    digitalWrite(SD_CS, HIGH);

    tft.init();
    tft.setRotation(1);  // Поворот дисплея, может потребоваться изменить в зависимости от ориентации вашего дисплея
    tft.fillScreen(TFT_BLACK);  // Очистка экрана черным цветом
    tft.setTextColor(TFT_WHITE);  // Установка цвета текста белым
    tft.setTextSize(2);  // Установка размера текста

    // Вывод тестового сообщения на дисплей
    tft.setCursor(10, 10);
    tft.println("Display Initialized!");
 
}