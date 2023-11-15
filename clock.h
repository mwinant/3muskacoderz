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

//    std::string countdownString;
//    std::ostringstream convert;

    //int countdown = 30;

};

#endif