#ifndef GUI_H
#define GUI_H

#include <Arduino.h>
#include "display.h"
#include <lvgl.h>
/*
 * Функция инициализации графического интерфейса, LVGL. 
 */ 
void gui_init(void); 
void process_gui(void); 
#endif // GUI_H