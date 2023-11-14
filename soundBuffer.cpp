#include "soundBuffer.h"


SoundBuffer::SoundBuffer(){
    
    mBuffer.loadFromFile("sounds/shotgun.wav");
   
}

const sf::SoundBuffer& SoundBuffer::getBuffer() const {
    return mBuffer;
}
