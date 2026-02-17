#include <Arduino.h>
#include <FS.h>
#include <SD.h>
#include <SPI.h>

#include "sdd.h"

// Пины SD на HSPI 
#define HSPI_MISO   35
#define HSPI_MOSI   13
#define HSPI_SCLK   14
#define HSPI_CS     5

// Пин CS дисплея
#define TFT_CS      26

static SPIClass *hspi = nullptr;
static bool sd_ok = false;

/*
 * Функция инициализирует SD-карту
 */
bool sd_init()
{
    Serial.println("Инициализация SD-карты (HSPI)...");

    // Создание HSPI 
    if (hspi == nullptr) {
        hspi = new SPIClass(HSPI);
        hspi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_CS);
    }

    pinMode(HSPI_CS, OUTPUT);
    digitalWrite(HSPI_CS, HIGH);

    sd_ok = SD.begin(HSPI_CS, *hspi, 1000000);
    if (!sd_ok) {
        Serial.println("Не удалось инициализировать SD-карту");
        return false;
    }

    uint8_t cardType = SD.cardType();
    Serial.print("Карта инициализирована. Тип: ");
    if (cardType == CARD_MMC) Serial.println("MMC");
    else if (cardType == CARD_SD) Serial.println("SDSC");
    else if (cardType == CARD_SDHC) Serial.println("SDHC");
    else Serial.println("UNKNOWN");

    uint64_t cardSize = SD.cardSize() / (1024ULL * 1024ULL);
    Serial.printf("Размер: %llu MB\n", cardSize);

    return true;
}

/*
 * Функция открывает файл 
 */
bool sd_append(const char *path, const char *text)
{
    if (!sd_ok) {
        Serial.println("Запись невозможна: SD не инициализирована");
        return false;
    }

    File file = SD.open(path, FILE_APPEND);
    if (!file) {
        Serial.printf("Не удалось открыть файл для добавления: %s\n", path);
        return false;
    }

    size_t written = file.print(text);
    file.close();

    if (written == 0) {
        Serial.println("Запись не удалась (0 байт)");
        return false;
    }

    Serial.printf("Записано %u байт в %s\n", (unsigned)written, path);
    return true;
}

/*
 * Фуекция записывает одну строку CSV
 */
bool data_recording(const char *timeHM, int t, int h, float dust)
{
    // CSV: HH:MM,temp,hum,dust
    char line[80];
    snprintf(line, sizeof(line), "%s,%d,%d,%.0f\n", timeHM, t, h, dust);

    Serial.print("Строка: ");
    Serial.print(line);

    return sd_append("/data.csv", line);
}
