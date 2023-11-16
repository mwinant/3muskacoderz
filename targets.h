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
#include <cstdlib>
#include "score.h"

const int POS_INC = 3,
        NEG_INC = -3,
        BODY_X_OFF = 5,
        BODY_Y_OFF = 4,
        HEAD_R_X_OFF = 12,
        HEAD_L_X_OFF = 25,
        HEAD_Y_OFF = 20;

class Deer
{
public:
    Deer();
    ~Deer(){};

    int gameLoop(sf::RenderWindow& window, Score &score, sf::Vector2u& winSize, bool &deerHit);
    void renderTarget(sf::RenderWindow& window);
    void renderHitText(sf::RenderWindow& window);
    bool moveDeer(sf::Vector2u& winSize);
    bool isHit(sf::RenderWindow& window, Score &score);
    void newPosition();
    void update(sf::Vector2u& winSize);
    void changeDirection(bool random);
    void updateAnimation();
    

private:
    sf::Sprite mDeer;
    sf::RectangleShape mBodyTarget;
    sf::CircleShape mHeadTarget;
    sf::Texture mTexture;
    sf::Vector2u spriteSize;
    int positionX,
        positionY,
        mAnimation,
        mDirection; //1 means the deer moves to the right, 2 means the deer moves to the left
    sf::Vector2f mIncrement;
    sf::Text hitText;
    sf::Font hitFont;
};




#endif