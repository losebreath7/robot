#include "gui.h"

static uint32_t my_tick_get_cb(void)
{
    //  Функция для получения текущего времени в миллисекундах
    //  Это необходимо для корректной работы LVGL
    return millis();
}

static void my_flush_cb(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
    int32_t x1 = area->x1;
    int32_t y1 = area->y1;
    int32_t x2 = area->x2;
    int32_t y2 = area->y2;
    
    // Установить область рисования на дисплее
    tft.setAddrWindow(x1, y1, (x2 - x1 + 1), (y2 - y1 + 1));
    
    // Отправить пиксельные данные на дисплей
    tft.pushColors((uint16_t *)px_map, (x2 - x1 + 1) * (y2 - y1 + 1), false);
    
    // Уведомить LVGL об окончании обновления дисплея
    lv_disp_flush_ready(disp);
}


void gui_init(void)
{
   //  1. Инициализация библиотеки LVGL
   lv_init(); 

   //  2. Инициализация тактирования для LVGL
   lv_tick_set_cb(my_tick_get_cb);
   
   //  3. Инициализация дисплея и его драйвера
    lv_display_t* display = lv_display_create(TFT_HOR_RES, TFT_VER_RES);

   // 4. Создание буфера для дисплея
   static uint8_t buf[TFT_HOR_RES * TFT_VER_RES / 10 * 2]; /* x2 ПОТОМУ ЧТО 16 БИТНАЯ ГЛУБИНА ЦВЕТА */ 
    
   // 5. Установка функции для обновления дисплея
   lv_display_set_flush_cb(display, my_flush_cb);

   // HELLO WORLD LVGL
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello, LVGL!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

void process_gui(void)
{
    //  Функция для обработки событий LVGL
    //  Должна вызываться в основном цикле программы
    lv_timer_handler();
    delay(5);  
}