#include "reticle.h"
#include <iostream>


Reticle::Reticle(){
    mTexture.loadFromFile("images/reticle.png");
    mSprite.setTexture(mTexture);
    mSprite.setOrigin(mSprite.getLocalBounds().width / 2, mSprite.getLocalBounds().height / 2);
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
