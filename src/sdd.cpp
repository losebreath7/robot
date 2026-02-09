#include <Arduino.h>
#include <FS.h>
#include <SD.h>

#include "sdd.h"

/*  Инициализирует модуль SD-карты.
 *  Выполняет подключение SD-карты по SPI и проверяет её доступность.
 *
 *  Возвращает:
 *  true  — если SD-карта успешно инициализирована,
 *  false — если инициализация не удалась.
 */
bool sd_init() {
    if (!SD.begin(CS_PIN)) {
        Serial.println("Не удалось инициализировать SD");
        return false;
    }
    Serial.println("Успешная инициализация SD");
    return true;
}

/*  Добавляет текстовую строку в файл на SD-карте.
 *  Открывает файл в режиме добавления (FILE_APPEND) и записывает переданные данные.
 *
 *  Параметры:
 *  path — путь к файлу на SD-карте,
 *  text — строка данных для записи.
 *
 *  Возвращает:
 *  true  — если запись выполнена успешно,
 *  false — если файл не удалось открыть или записать данные.
 */
bool sd_append(const char* path, const char* text) {
    File file = SD.open(path, FILE_APPEND);
    if (!file) {
        Serial.println("Не удалось открыть файл для добавления данных.");
        return false;
    }

    file.print(text);
    file.close();
    return true;
}

/*  Выполняет сбор данных и их запись на SD-карту.
 *  Получает текущее время, считывает значения температуры и влажности,
 *  формирует строку в формате CSV и сохраняет её в файл журнала.
 */
bool data_recording() {
  // получение данных
  String ts = time_getString();   
  int t = Temperature();
  int h = Humidity();

  // форматирование в строку CSV
  char line[64];
  snprintf(line, sizeof(line), "%s,%d,%d\n", ts.c_str(), t, h);

  // 3) запись данных на карту
  return sd_append("/log.csv", line);
}



