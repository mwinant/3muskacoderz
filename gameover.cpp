/**
 * @file gameover.cpp
 * @author Mikayla Winant
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "gameover.h"
#include <iostream>

GameOver::GameOver(){
    if(!texture.loadFromFile("images/gameOverbackground.png")){
        std::cout<<"Error loading game over background image\n";
    }
    sprite.setTexture(texture); //background image
    sprite.setScale(.6,.5);

    if(!texture2.loadFromFile("images/gameOverDeer.png")){
        std::cout<<"Error loading game over deer image\n";
    }
    sprite2.setTexture(texture2);
    sprite2.setScale(.1,.1);
    sprite2.setPosition(480.f,350.f);

    font.loadFromFile("images/GameOver.ttf");
    text.setFont(font);
    text.setString("GAME OVER");
    text.setCharacterSize(75);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(93,63,211));
    text.setFillColor(sf::Color::White);
    text.setPosition(95.f,25.f);

}