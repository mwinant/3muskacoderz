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