/**
 * @file targets.cpp
 * @author Justin Bradshaw
 * @brief Has the functions for the Class Deer
 * @version 0.1
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "targets.h"
#include "extra.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 */
Deer::Deer(){
    mTexture.loadFromFile("images/PIX_deer_upright.png");
    mDeer.setTexture(mTexture);
    spriteSize = mTexture.getSize();
    mDeer.setOrigin(spriteSize.x / 2, spriteSize.y / 2);
    positionX = randomNumber(40, 640);
    positionY = randomNumber(250, 440);
    mDeer.setPosition(positionX,positionY);
    mDeer.setScale(.1f, .1f);
    direction = randomNumber(0,1);
    mIncrement = sf::Vector2f(1, 1);
}

/**
 * @brief Check to see if the deer has been hit or not
 * 
 * @param window Is the window that was created in main.cpp for the game
 * @return true means that the deer has been hit
 * @return false means that the deer has not been hit
 */
bool Deer::isHit(sf::RenderWindow&window){

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //gun.fire();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::FloatRect spriteBounds = mDeer.getGlobalBounds();
        if (spriteBounds.contains(sf::Vector2f(mousePosition))) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Sets a new position for the deer
 * 
 */
void Deer::newPosition(){
    positionX = randomNumber(40, 600);
    positionY = randomNumber(250, 440);
    mDeer.setPosition(positionX,positionY);
}

/**
 * @brief Draws the deer in the window
 * 
 * @param window Is the window that was created in main.cpp for the game
 */
void Deer::renderTarget(sf::RenderWindow& window){
    window.draw(mDeer);
}


/**
 * @brief Update objects in the scene
 * 
 */
void Deer::update(sf::RenderWindow& window)
{
    moveDeer(window);
}

/**
 * @brief Moves the deer to update the scene. Calculates the direction to move the deer
 * 
 */
void Deer::moveDeer(sf::RenderWindow& window){
    sf::Vector2u winSize = window.getSize();
    if ((mDeer.getPosition().x + (spriteSize.x/ 2) > winSize.x && mIncrement.x > 0) ||
    (mDeer.getPosition().x - (spriteSize.x / 2) < 0 && mIncrement.x < 0)){
        mIncrement.x = -mIncrement.x;
    }
    mDeer.setPosition(mDeer.getPosition().x+mIncrement.x,mDeer.getPosition().y);
}


