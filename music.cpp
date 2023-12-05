/**
 * @file music.cpp
 * @author Sialas Tripp
 * @brief music class definition file
 * @date 2023-12-04
 * 
 */
#include "music.h"

/**
 * @brief Music class constructor
 * 
 */
Music::Music(){
    mMusic.openFromFile("sounds/intro.wav");
    mMusic.setVolume(100);
    mMusic.setLoop(true);
}
