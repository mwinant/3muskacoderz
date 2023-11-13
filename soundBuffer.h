#ifndef SOUNDBUFFER_H
#define SOUNDBUFFER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SoundBuffer{
public:
    SoundBuffer();
    ~SoundBuffer(){};
    const sf::SoundBuffer& getBuffer() const;
    sf::SoundBuffer mBuffer;
};

#endif