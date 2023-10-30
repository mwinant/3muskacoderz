#include <SFML/Graphics.hpp>
#include "background.h"

int main(){

    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Buck Hunter");
    Background background;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }
    window.clear();
    window.draw(background.mSprite);
    window.display();
    }
    return 0;
}