#include "coverArt.h"
#include <iostream>

CoverArt::CoverArt(){
    if(!texture.loadFromFile("images/deer.png")){
        std::cout<<"Error loading deer image\n";
    }
    deerSprite.setTexture(texture);

    font.loadFromFile("images/PressStart2P.ttf");
    text.setFont(font);
    text.setString("Press Enter to Start");
    text.setCharacterSize(20);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setFillColor(sf::Color::White);
    text.setPosition(95.f,400.f);

    font2.loadFromFile("images/westernFont.ttf");
    text2.setFont(font2);
    text2.setString("Big Buck Hunter");
    text2.setCharacterSize(70);
    text2.setOutlineThickness(2);
    text2.setOutlineColor(sf::Color::White);
    text2.setFillColor(sf::Color(92,64,51));
    text2.setPosition(105.f,50.f);
}

