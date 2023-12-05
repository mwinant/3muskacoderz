/**
 * @file soundBuffer.cpp
 * @author Sialas Tripp
 * @brief sound buffer class definition file
 * @date 2023-12-04
 * 
 */
#include "soundBuffer.h"

/**
 * @brief sound buffer constructor
 * 
 */
SoundBuffer::SoundBuffer(){
    
    mBuffer.loadFromFile("sounds/shotgun.wav");
   
}

/**
 * @brief gets the sound buffer
 * 
 * @return const sf::SoundBuffer&  returns sound buffer
 */
const sf::SoundBuffer& SoundBuffer::getBuffer() const {
    return mBuffer;
}
