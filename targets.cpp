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
#include <iostream>

/**
 * @brief Construct a new Game:: Game object
 * 
 */ 
Deer::Deer(){
    mDirection = randomNumber(1,2);  //1 means the deer moves to the right, 2 means the deer moves to the left
    std::cout<<"The direction is: "<<mDirection<<std::endl;
    if(mDirection == 1){
        mTexture.loadFromFile("images/PIX_deer_upright_Rface.png");
        mIncrement = sf::Vector2f(POS_INC, POS_INC);
    } else{
        mTexture.loadFromFile("images/PIX_deer_upright_Lface.png");
        mIncrement = sf::Vector2f(NEG_INC, NEG_INC);
    }
    mDeer.setTexture(mTexture);
    spriteSize = mTexture.getSize();
    mDeer.setOrigin(spriteSize.x / 2, spriteSize.y / 2);
    positionX = randomNumber(40, 640);
    positionY = randomNumber(250, 440);
    mDeer.setPosition(positionX,positionY);
    mDeer.setScale(.1f, .1f);
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
void Deer::update(sf::Vector2u& winSize){
    if(!moveDeer(winSize))   //Checks if deer is outside the window and flips it if it is.
        changeDirection(true);  //Randomly flips deer's direction
}

/**
 * @brief Moves the deer to update the scene. Calculates the direction to move the deer
 * 
 */
bool Deer::moveDeer(sf::Vector2u& winSize){
    bool offScreen = false;
    // sf::Vector2u winSize = window.getSize();
    if ((mDeer.getPosition().x + (spriteSize.x/ 2) > (winSize.x*2)/* && mIncrement.x > 0*/)){
        mTexture.loadFromFile("images/PIX_deer_upright_Lface.png");
        mIncrement = sf::Vector2f(NEG_INC, NEG_INC);
        mDirection = 2;
        offScreen = true;
        std::cout<<"DEER IS OFF RIGHT SCREEN\n";
    }else if((mDeer.getPosition().x - (spriteSize.x / 2) < 0/* && mIncrement.x < 0*/)){
        mTexture.loadFromFile("images/PIX_deer_upright_Rface.png");
        mIncrement = sf::Vector2f(POS_INC, POS_INC);
        mDirection = 1;
        offScreen = true;
        std::cout<<"DEER IS OFF LEFT SCREEN\n";
    }
    mDeer.setPosition(mDeer.getPosition().x+mIncrement.x,mDeer.getPosition().y);
    return offScreen;
}

/**
 * @brief Changes the direction of the deer. Both the way it is facing and mIncrement for the direction it moves.
 * 
 * @param random Should the change of direction be random chance? If yes, then true.
 */
void Deer::changeDirection(bool random){
    if(random){ //Checks if the change should be random
        int changeDirection = randomNumber(1,500);   //Gives a 0.2% chance that the deer will change direction
        if(changeDirection == 500){
            mDirection = randomNumber(1,2);  //50/50 chance on which direction the deer goes. 1 means the deer moves to the right, 2 means the deer moves to the left
            std::cout<<"The direction is: "<<mDirection<<std::endl;
            if(mDirection == 1){
                mTexture.loadFromFile("images/PIX_deer_upright_Rface.png");
                mIncrement = sf::Vector2f(POS_INC, POS_INC);
            } else{
                mTexture.loadFromFile("images/PIX_deer_upright_Lface.png");
                mIncrement = sf::Vector2f(NEG_INC, NEG_INC);
            }
        }
    }else if(!random){  //If the change should not be random, like if the deer goes off screen, then it changes the direction based on mDirection
        if(mDirection == 2){    //The deer was heading to the left, but now it is heading to the right
                mTexture.loadFromFile("images/PIX_deer_upright_Rface.png");
                mIncrement = sf::Vector2f(POS_INC, POS_INC);
                mDirection = 1;
            } else{             //The deer was heading to the right, but now it is heading to the left
                mTexture.loadFromFile("images/PIX_deer_upright_Lface.png");
                mIncrement = sf::Vector2f(NEG_INC, NEG_INC);
                mDirection = 2;
            }
    }
}