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