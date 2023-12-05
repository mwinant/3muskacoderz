/**
 * @file background.cpp
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "background.h"
//g++ *.cpp -I/opt/homebrew/Cellar/sfml/2.6.0/include -o main -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

//background image to be uded in game loop and title/cover
Background::Background(){
    mTexture.loadFromFile("images/background.png");
    mSprite.setTexture(mTexture);
    
}
