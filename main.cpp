#include <SFML/Graphics.hpp>
#include "background.h"
#include "coverArt.h"
#include "gameover.h"
#include "reticle.h"
#include "music.h"
#include "soundBuffer.h"
#include "sound.h"
#include "targets.h"
#include "extra.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>

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
    Deer deer;

    //GAME CLOCK AND TIMER
    sf::Clock clock;
    int countdown = 30;

    //CONVERT COUNTDOWN TO A STRING
    std::string countdownString;
    std::ostringstream convert;
    convert << countdown;
    countdownString = convert.str();

    //LOAD TIMER FONT AND TEXT
    sf::Text timerText;
    sf::Font timerFont;
    timerFont.loadFromFile("images/timerfont.ttf");
    timerText.setFont(timerFont);
    timerText.setString(countdownString);
    timerText.setPosition(600,5); //TODO fix
    timerText.setCharacterSize(40);

    // hides system mouse cursor
    window.setMouseCursorVisible(false);
    
    //play music
    music.mMusic.play();

    bool deerHit = false; //Checks if the deer has been hit. Temporary
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

        //TIMER - 30 SECONDS
        int timer = clock.getElapsedTime().asSeconds();

        if (timer > 0) {
            countdown--;
            timerText.setString(std::to_string(countdown));
            clock.restart();
        }
        // if(timer==0){
        //     //go to gameover screen
        // }

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


        int rand_chance = randomNumber(0, 100); //Returns a 1-100
        if(deerHit && rand_chance <= 1){    //on a 1/100 chance it sets the deer to a new position
            deerHit = false;    //Resets if it's been hit so that the deer is rendered again
            deer.newPosition(); //Sets a new random position for the deer
        }
        if(!deerHit){   //Renders the deer so long as it hasn't been shot
            deer.renderTarget(window);  //Function to draw deer
            deerHit = deer.isHit(window);   //Checks if deer has been hit
            //Render deer dying and display that instead if the deer gets hit
        }
        
        window.draw(timerText);
        window.display();
    }

    return 0;
}