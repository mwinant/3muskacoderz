/**
 * @file targets.h
 * @author Justin Bradshaw
 * @brief Holds the class for the Deer target
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TARGETS_H
#define TARGETS_H
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <random>

class Deer
{
public:
    Deer();
    ~Deer(){};

    // void handleInput();
    void renderTarget(sf::RenderWindow& window);
    void moveDeer(sf::RenderWindow& window);
    bool isHit(sf::RenderWindow& window);
    void newPosition();
    void update(sf::RenderWindow& window);
    

private:
    sf::Sprite mDeer;
    sf::Texture mTexture;
    sf::Vector2u spriteSize;
    int positionX,
        positionY,
        direction;
    sf::Vector2f mIncrement;
};




#endif