#ifndef TARGETS_H
#define TARGETS_H
#include <SFML/Graphics.hpp>

class Deer
{
public:
    Deer();
    ~Deer(){};

    // void handleInput();
    // void update();
    // void renderTarget(sf::RenderWindow window);
    // bool isDone() const;



    sf::Texture mTexture;
    sf::Sprite mDeer;
    // sf::Vector2i mIncrement;

    void moveDeer();
};




#endif