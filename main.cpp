#include <SFML/Graphics.hpp>
#include "background.h"
#include "coverArt.h"
#include "gameover.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Buck Hunter");
    Background background;
    CoverArt coverArt;
    GameOver gameOver;

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

            // if (event.type == sf::Event::KeyPressed
            //     && event.key.code == sf::Keyboard::Enter){
            //     //close cover screen and start game
            // }
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        reticle.setPosition(static_cast<sf::Vector2f>(mousePosition));

        window.clear();
        window.draw(background.mSprite);
        window.draw(coverArt.deerSprite);
        window.draw(coverArt.text);
        window.draw(coverArt.text2);
        window.draw(reticle);

        //Game Over Image
        // window.draw(gameOver.sprite);
        // window.draw(gameOver.sprite2);
        // window.draw(gameOver.text);

        window.display();
    }

    return 0;
}