#include "background.h"
//g++ *.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include -o main -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-system

//background image to be uded in game loop and title/cover
Background::Background(){
    mTexture.loadFromFile("images/background.png");
    mSprite.setTexture(mTexture);
    
}
