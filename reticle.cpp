/**
 * @file reticle.cpp
 * @author Sialas Tripp
 * @brief reticle class definition file
 * @date 2023-12-04
 */
#include "reticle.h"
#include <iostream>

/**
 * @brief Reticle class constructor
 * 
 */
Reticle::Reticle(){
    mTexture.loadFromFile("images/reticle.png");
    mSprite.setTexture(mTexture);
    mSprite.setOrigin(mSprite.getLocalBounds().width / 2.f, mSprite.getLocalBounds().height / 2.f);
    float scaleFactor = 0.25f; 
    mSprite.setScale(scaleFactor, scaleFactor);
    
}

/**
 * @brief Renders the reticle sprite
 * 
 * @param window The main game window
 */
void Reticle::renderReticle(sf::RenderWindow& window){
    window.draw(mSprite);
}
