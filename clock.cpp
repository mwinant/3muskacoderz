#include "clock.h"

Timer::Timer(){
    timerFont.loadFromFile("images/timerfont.ttf");
    timerText.setFont(timerFont);
    timerText.setPosition(600,5); 
    timerText.setCharacterSize(40);

    // timerText.setString(countdownString);

}