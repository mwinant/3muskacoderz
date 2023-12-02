#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <SFML/Graphics.hpp>

class GameOver{
public:
    GameOver();
    ~GameOver(){};

    sf::Texture texture; //background image
    sf::Sprite sprite;

    sf::Texture texture2; //deer
    sf::Sprite sprite2;

    sf::Text text;
    sf::Font font;

};

#endif