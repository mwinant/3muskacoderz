/**
 * @file clock.h
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

class Timer{
public:
    Timer();
    ~Timer(){};

    sf::Clock clock;
    sf::Text timerText;
    sf::Font timerFont;

};

#endif