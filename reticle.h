#ifndef RETICLE_H
#define RETICLE_H
#include <SFML/Graphics.hpp>

class Reticle{
public:
    Reticle();
    ~Reticle(){};
    sf::Texture mTexture;
    sf::Sprite mSprite;
};

#endif