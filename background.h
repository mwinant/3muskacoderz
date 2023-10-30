#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Background{
public:
    Background();
    ~Background(){};
    sf::Texture mTexture;
    sf::Sprite mSprite;
};

#endif