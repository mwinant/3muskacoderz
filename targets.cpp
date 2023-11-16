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
#include "score.h"
#include <iostream>

/**
 * @brief Construct a new Game:: Game object
 * 
 */ 
Deer::Deer(){
    mDirection = randomNumber(1,2);  //1 means the deer moves to the right, 2 means the deer moves to the left
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
    mBodyTarget.setSize(sf::Vector2f(40.f, 21.f));
    mBodyTarget.setFillColor(sf::Color(0,0,0,0));
    mBodyTarget.setOrigin(40/2, 21/2);
    mHeadTarget.setRadius(7.f);
    mHeadTarget.setFillColor(sf::Color(0,0,0,0));
    if(mDirection == 1){
        mBodyTarget.setPosition(mDeer.getPosition().x-BODY_X_OFF, mDeer.getPosition().y+BODY_Y_OFF);
        mHeadTarget.setPosition(mDeer.getPosition().x+HEAD_R_X_OFF, mDeer.getPosition().y-HEAD_Y_OFF);
    } else{
        mBodyTarget.setPosition(mDeer.getPosition().x+BODY_X_OFF, mDeer.getPosition().y+BODY_Y_OFF);
        mHeadTarget.setPosition(mDeer.getPosition().x-HEAD_L_X_OFF, mDeer.getPosition().y-HEAD_Y_OFF);
    }
    hitFont.loadFromFile("images/scoreFont.ttf");
    hitText.setFont(hitFont);
    hitText.setPosition(300,200);
    hitText.setCharacterSize(50);
    hitText.setString("HIT!");
    mAnimation = 0;
}


int Deer::gameLoop(sf::RenderWindow& window, Score &score, sf::Vector2u& winSize, bool &deerHit){
    int hitTimer = 0;
    int rand_chance = randomNumber(0, 100); //Returns a 1-100
    if(deerHit && rand_chance <= 1){    //on a 1/100 chance it sets the deer to a new position
        deerHit = false;    //Resets if it's been hit so that the deer is rendered again
        newPosition(); //Sets a new random position for the deer
    }
    if(!deerHit){   //Renders the deer so long as it hasn't been shot
        update(winSize);    //Function to update the deer. Thus far it only calls the moveDeer function.
        renderTarget(window);  //Function to draw deer
        deerHit = isHit(window, score);   //Checks if deer has been hit
        if(deerHit)
            hitTimer = 30;  //Sets the hit "timer" to 30 so that it will display for 30 cycles of the game loop
        score.renderScore(window);
                //Render deer dying and display that instead if the deer gets hit
    }
    return hitTimer;
}


/**
 * @brief Check to see if the deer has been hit or not
 * 
 * @param window Is the window that was created in main.cpp for the game
 * @return true means that the deer has been hit
 * @return false means that the deer has not been hit
 */
bool Deer::isHit(sf::RenderWindow&window, Score &score){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        //gun.fire();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::FloatRect bodyBounds = mBodyTarget.getGlobalBounds();
        if (bodyBounds.contains(sf::Vector2f(mousePosition))) {
            score.updateScore(1);
            hitText.setPosition(mDeer.getPosition().x, mDeer.getPosition().y-50);
            renderHitText(window);
            return true;
        }
        sf::FloatRect headBounds = mHeadTarget.getGlobalBounds();
        if (headBounds.contains(sf::Vector2f(mousePosition))) {
            score.updateScore(3);
            hitText.setPosition(mDeer.getPosition().x, mDeer.getPosition().y-50);
            renderHitText(window);
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
    window.draw(mBodyTarget);
    window.draw(mHeadTarget);
}


void Deer::renderHitText(sf::RenderWindow& window){
    window.draw(hitText);
}


/**
 * @brief Update objects in the scene
 * 
 */
void Deer::update(sf::Vector2u& winSize){
    if(!moveDeer(winSize))   //Checks if deer is outside the window and flips it if it is.
        changeDirection(true);  //Randomly flips deer's direction
    // updateAnimation();   //Used to update the annimation so that it looks like the deer is running
}

/**
 * @brief Moves the deer to update the scene. Calculates the direction to move the deer
 * 
 */
bool Deer::moveDeer(sf::Vector2u& winSize){
    bool offScreen = false;
    if ((mDeer.getPosition().x + (spriteSize.x/ 2) > (winSize.x*1.5)/* && mIncrement.x > 0*/)){
        mTexture.loadFromFile("images/PIX_deer_upright_Lface.png");
        mIncrement = sf::Vector2f(NEG_INC, NEG_INC);
        mDirection = 2;
        offScreen = true;
    }else if((mDeer.getPosition().x - (spriteSize.x / 2) < (winSize.x*-0.5)/* && mIncrement.x < 0*/)){
        mTexture.loadFromFile("images/PIX_deer_upright_Rface.png");
        mIncrement = sf::Vector2f(POS_INC, POS_INC);
        mDirection = 1;
        offScreen = true;
    }
    mDeer.setPosition(mDeer.getPosition().x+mIncrement.x,mDeer.getPosition().y);
    if(mDirection == 1){
        mBodyTarget.setPosition(mDeer.getPosition().x-BODY_X_OFF, mDeer.getPosition().y+BODY_Y_OFF);
        mHeadTarget.setPosition(mDeer.getPosition().x+HEAD_R_X_OFF, mDeer.getPosition().y-HEAD_Y_OFF);
    } else{
        mBodyTarget.setPosition(mDeer.getPosition().x+BODY_X_OFF, mDeer.getPosition().y+BODY_Y_OFF);
        mHeadTarget.setPosition(mDeer.getPosition().x-HEAD_L_X_OFF, mDeer.getPosition().y-HEAD_Y_OFF);
    }
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


/**
 * @brief Updates the annimation of the dear through a cycle based on the number in mAnimation
 * 
 */
void Deer::updateAnimation(){
    if(mAnimation == 0){
        mTexture.loadFromFile("images/deer_1_animation.png");
        mAnimation = 1;
    }else if(mAnimation == 1){
        mTexture.loadFromFile("images/deer_2_animation.png");
        mAnimation = 2;
    }else{
    mTexture.loadFromFile("images/deer_0_animation.png");
        mAnimation = 0;
    }
}