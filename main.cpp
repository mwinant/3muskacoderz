#include <SFML/Graphics.hpp>
#include "background.h"
#include "coverArt.h"
#include "gameover.h"
#include "reticle.h"
#include "music.h"
#include "soundBuffer.h"
#include "sound.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Buck Hunter");
    Background background;
    Reticle reticle;
    Music music;
    CoverArt coverArt;
    GameOver gameOver;
    SoundBuffer buffer;
    Sound sound(buffer);

    // hides system mouse cursor
    window.setMouseCursorVisible(false);
    
    //play music
    music.mMusic.play();


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
            // Mouse button pressed: play the sound
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sound.mSound.play();
            }
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