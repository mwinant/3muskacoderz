/**
 * @file clock.cpp
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "clock.h"

Timer::Timer(){
    timerFont.loadFromFile("images/timerfont.ttf");
    timerText.setFont(timerFont);
    timerText.setPosition(600,5); 
    timerText.setCharacterSize(40);

}