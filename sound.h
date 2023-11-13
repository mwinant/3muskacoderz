#ifndef SOUND_H
#define SOUND_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "soundBuffer.h"

class Sound{
public:
    Sound(const SoundBuffer& SoundBuffer);
    ~Sound(){};
    sf::Sound mSound;
};

#endif