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

void drawTime(void); 
void UpdateTime(const char * time);

void drawHum(void); 
void UpdateHum(float humidity);

void drawTemperature(void);
void updateTemperature(float temperature);


#endif // GUI_H
