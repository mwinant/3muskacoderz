/**
 * @file getName.cpp
 * @author Sialas
 * @brief getName definition file
 * @date 2023-12-04
 * 
 */
#include "getName.h"
#include <iostream>

/**
 * @brief Get Name constructor
 * 
 */
GetName::GetName(){
    if(!texture.loadFromFile("images/gameOverbackground.png")){
        std::cout<<"Error loading game over background image\n";
    }
    sprite.setTexture(texture); 
    sprite.setScale(.6,.5);

    if(!texture2.loadFromFile("images/gameOverDeer.png")){
        std::cout<<"Error loading game over deer image\n";
    }
    sprite2.setTexture(texture2);
    sprite2.setScale(.1,.1);
    sprite2.setPosition(480.f,350.f);

    font.loadFromFile("images/GameOver.ttf");
    text.setFont(font);
    text.setString("GAME Over");
    text.setCharacterSize(75);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(93,63,211));
    text.setFillColor(sf::Color::White);
    text.setPosition(95.f,150.f);

    namePromptText.setFont(font);
    namePromptText.setString("Enter your name:");
    namePromptText.setCharacterSize(20);
    namePromptText.setPosition(200, 300);

    playerNameText.setFont(font);
    playerNameText.setCharacterSize(20);
    playerNameText.setPosition(200, 330);
    
}