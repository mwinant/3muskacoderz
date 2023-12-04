/**
 * @file background.h
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>

class Background{
public:
    Background();
    ~Background(){};
    sf::Texture mTexture;
    sf::Sprite mSprite;
};

#endif