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

const int POS_INC = 5,
        NEG_INC = -5;

class Deer
{
public:
    Deer();
    ~Deer(){};

    // void handleInput();
    void renderTarget(sf::RenderWindow& window);
    bool moveDeer(sf::Vector2u& winSize);
    bool isHit(sf::RenderWindow& window);
    void newPosition();
    void update(sf::Vector2u& winSize);
    void changeDirection(bool random);
    

private:
    sf::Sprite mDeer;
    sf::Texture mTexture;
    sf::Vector2u spriteSize;
    int positionX,
        positionY,
        mDirection; //1 means the deer moves to the right, 2 means the deer moves to the left
    sf::Vector2f mIncrement;
};




#endif