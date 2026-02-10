#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>
#include <SPI.h>

#define TFT_HOR_RES 220
#define TFT_VER_RES 170

extern TFT_eSPI tft;  // СОЗДАЕМ ОБЬЕКТ, ПИНЫ ОПРЕДЕЛНЫ В User_Setup.h
/*
 * ИНИЦИАЛИЗАЦИЯ ДИСПЛЕЯ 2.2" TFT SPI 220x170 ILI9225
 */
void DisplayInit(void);

/*
 * ДИСПЛЕЙ 2.2" TFT SPI 220x170 ILI9225
 *  
 * */

 // ТУТ УЖЕ БУДУТ ПОЛЬЗОВАТЕЛЬСКИЕ ФУНКЦИИ
 
 
#endif // DISPLAY_H