/**
 * @file reticle.h
 * @author Sialas Tripp
 * @brief reticle class header file
 * @date 2023-12-04
 * 
 */
#ifndef RETICLE_H
#define RETICLE_H
#include <SFML/Graphics.hpp>

class Reticle{
public:
    Reticle();
    ~Reticle(){};
    void renderReticle(sf::RenderWindow& window);
    sf::Texture mTexture;
    sf::Sprite mSprite;
};

#endif