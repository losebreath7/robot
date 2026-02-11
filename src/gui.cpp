#include "gui.h"

// ОТОБРАЖЕНИЕ ВРЕМЕНИ 
static lv_obj_t *time_label = NULL;
// ОТОБРАЖЕНИЕ ВЛАЖНОСТИ
static lv_obj_t * hum_label = NULL;
// ОТОБРАЖЕНИЕ ТЕМПЕРАТУРЫ
static lv_obj_t *temp_label = NULL;


static uint8_t buf[TFT_HOR_RES * TFT_VER_RES / 10 * 2]; /* x2 ПОТОМУ ЧТО 16 БИТНАЯ ГЛУБИНА ЦВЕТА */

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

        // 5. Установка функции для обновления дисплея
    lv_display_set_flush_cb(display, my_flush_cb);
    
    // устновка буфера 
    lv_display_set_buffers(display, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    // HELLO WORLD LVGL
    //lv_obj_t * label = lv_label_create(lv_scr_act());
    //lv_label_set_text(label, "Hello, LVGL!");
    //lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    
}

void process_gui(void)
{
    //  Функция для обработки событий LVGL
    //  Должна вызываться в основном цикле программы
    lv_timer_handler();
    delay(5);  
}

void drawTime(void){
     
    if (time_label == NULL) {
        time_label = lv_label_create(lv_screen_active());
        lv_obj_set_style_text_font(time_label, &lv_font_montserrat_28, 0);
        lv_obj_set_style_text_color(time_label, lv_color_hex(0xFFFFFF), 0);
        lv_obj_set_style_bg_color(time_label, lv_color_hex(0x333333), 0);
        lv_obj_set_style_bg_opa(time_label, LV_OPA_70, 0);
        lv_obj_set_style_pad_all(time_label, 10, 0);
        lv_obj_set_style_radius(time_label, 10, 0);
        lv_obj_align(time_label, LV_ALIGN_TOP_RIGHT, -10, 10);

     }
}; 

void UpdateTime(const char * time){
    lv_label_set_text(time_label, time);
};


void drawHum(void){

    if (hum_label == NULL) {
        hum_label = lv_label_create(lv_screen_active());
        lv_obj_set_style_text_font(hum_label, &lv_font_montserrat_28, 0);
        lv_obj_set_style_text_color(hum_label, lv_color_hex(0xFFFFFF), 0);
        lv_obj_set_style_bg_color(hum_label, lv_color_hex(0x333333), 0);
        lv_obj_set_style_bg_opa(hum_label, LV_OPA_70, 0);
        lv_obj_set_style_pad_all(hum_label, 10, 0);
        lv_obj_set_style_radius(hum_label, 10, 0);
        lv_obj_align(hum_label, LV_ALIGN_TOP_LEFT, 10, 10);

     }
}

void UpdateHum(float humidity){
    char buf[32];
    snprintf(buf, sizeof(buf), " %0.f %%", humidity);
    lv_label_set_text(hum_label, buf);
}

void drawTemperature(void) {
    //static lv_obj_t *temp_label = NULL;

    if (temp_label == NULL) {
        temp_label = lv_label_create(lv_screen_active());

        lv_obj_set_style_text_font(temp_label, &lv_font_montserrat_28, 0);
        lv_obj_set_style_text_color(temp_label, lv_color_hex(0xFFFFFF), 0);
        lv_obj_set_style_bg_color(temp_label, lv_color_hex(0x333333), 0);
        lv_obj_set_style_bg_opa(temp_label, LV_OPA_70, 0);
        lv_obj_set_style_pad_all(temp_label, 10, 0);
        lv_obj_set_style_radius(temp_label, 10, 0);

        lv_obj_align(temp_label, LV_ALIGN_TOP_LEFT, 10, 80);
        //lv_label_set_text(temp_label, "Temp: -- °C");
    }
}

void updateTemperature(float temperature) {
    char buf[32];
    snprintf(buf, sizeof(buf), "Temp: %0.f °C", temperature);
    lv_label_set_text(temp_label, buf);
}
