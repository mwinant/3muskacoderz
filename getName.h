#ifndef GETNAME_H
#define GETNAME_H
#include <SFML/Graphics.hpp>

class GetName{
public:
    GetName();
    ~GetName(){};

    sf::Texture texture; 
    sf::Sprite sprite;

    sf::Texture texture2;
    sf::Sprite sprite2;

    sf::Text text;
    sf::Font font;

    sf::Text namePromptText;
    sf::Text playerNameText;
    sf::String playerName;
};




#endif