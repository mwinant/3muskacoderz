#ifndef COVERART_H
#define COVERART_H
#include <SFML/Graphics.hpp>

class CoverArt{
public:
    CoverArt();
    ~CoverArt(){};

    sf::Font font; //press start to continue
    sf::Font font2; //Big Buck Hunter 2.0

    sf::Text text;
    sf::Text text2;

    sf::Texture texture; //deer image
    sf::Sprite deerSprite;


};





#endif

