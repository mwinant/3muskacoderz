#include <SFML/Graphics.hpp>
#include "background.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Buck Hunter");
    Background background;

    // hides system mouse cursor
    window.setMouseCursorVisible(false);

    
    //change the mouse cursor to reticle
    sf::Texture texture;
    texture.loadFromFile("images/reticle.png");
    sf::Sprite reticle(texture);
    reticle.setOrigin(reticle.getLocalBounds().width / 2, reticle.getLocalBounds().height / 2);

    // sets scale of reticle to be smaller
    float scaleFactor = .25f; 
    reticle.setScale(scaleFactor, scaleFactor);
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        reticle.setPosition(static_cast<sf::Vector2f>(mousePosition));

        window.clear();
        window.draw(background.mSprite);
        window.draw(reticle);
        window.display();
    }

    return 0;
}