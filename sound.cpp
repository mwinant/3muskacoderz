/**
 * @file sound.cpp
 * @author Sialas Tripp
 * @brief sound class definition file
 * @date 2023-12-04
 * 
 */
#include "sound.h"

/**
 * @brief sound class constructor
 * 
 * @param buffer 
 */
Sound::Sound(const SoundBuffer& buffer){
    mSound.setBuffer(buffer.getBuffer());
   
}
