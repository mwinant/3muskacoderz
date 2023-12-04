/**
 * @file music.h
 * @author Sialas Tripp
 * @brief music class header file
 * @date 2023-12-04
 * 
 */
#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Music{
public:
    Music();
    ~Music(){};
    sf::Music mMusic;
};

#endif