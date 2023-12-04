/**
 * @file soundBuffer.h
 * @author Sialas Tripp
 * @brief sound buffer header file
 * @date 2023-12-04
 * 
 */
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