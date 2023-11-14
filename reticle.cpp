#include "reticle.h"


Reticle::Reticle(){
    mTexture.loadFromFile("images/reticle.png");
    mSprite.setTexture(mTexture);
    mSprite.setOrigin(mSprite.getLocalBounds().width / 2, mSprite.getLocalBounds().height / 2);
    float scaleFactor = 0.25f; 
    mSprite.setScale(scaleFactor, scaleFactor);
    
}
