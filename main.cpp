#include <SFML/Graphics.hpp>
#include "background.h"
#include "coverArt.h"
#include "gameover.h"
#include "reticle.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Buck Hunter");
    Background background;
    Reticle reticle;
    CoverArt coverArt;
    GameOver gameOver;

    // hides system mouse cursor
    window.setMouseCursorVisible(false);

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
        reticle.mSprite.setPosition(static_cast<sf::Vector2f>(mousePosition));

        window.clear();
        window.draw(background.mSprite);
        window.draw(coverArt.deerSprite);
        window.draw(coverArt.text);
        window.draw(coverArt.text2);
        window.draw(reticle.mSprite);

        //Game Over Image
        // window.draw(gameOver.sprite);
        // window.draw(gameOver.sprite2);
        // window.draw(gameOver.text);

        window.display();
    }

    return 0;
}