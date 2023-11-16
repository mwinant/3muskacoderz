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
#include "screen.h"
#include "clock.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>

int main()
{
    TitleScreen titlescreen;
    GameLoopScreen gameloopscreen;
    GameOverScreen gameOverScreen;
    titlescreen.active=true; //sets titlescreen as first screen
    
    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Elk Hunter");
    sf::Vector2u winSize = window.getSize();
    Reticle reticle;
    Music music;
    SoundBuffer buffer;
    Sound sound(buffer);
    Deer deer;
    Timer timer;

    //Sets framerate to 60fps
    window.setFramerateLimit(60);

    //FOR TIMER
    int countdown;
    //CONVERT COUNTDOWN TO A STRING
    std::string countdownString;
    std::ostringstream convert;
    convert << countdown;
    countdownString = convert.str();
    timer.timerText.setString(countdownString);

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

            if (event.type == sf::Event::KeyPressed
                && event.key.code == sf::Keyboard::Enter){
                //close cover screen and start game
                gameloopscreen.active=true;
                titlescreen.active=false;
                countdown=30;
            }
            // Mouse button pressed: play the sound
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sound.mSound.play();
            }
        }
        
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        reticle.mSprite.setPosition(static_cast<sf::Vector2f>(mousePosition));

        //CONTROLS TIMER
        int time=timer.clock.getElapsedTime().asSeconds();
        if (time > 0) {
            countdown--;
            timer.timerText.setString(std::to_string(countdown));
            timer.clock.restart();
        }
        //CHANGES SCREEN FROM GAMELOOP TO GAMEOVER ONCE THE TIMER REACHES ZERO
        if(countdown<=-1){
            gameloopscreen.active=false;
            gameOverScreen.active=true;   
        } 

        //CONTROLS TITLE, GAMELOOP, AND GAMEOVER SCREENS
        window.clear();
        if(titlescreen.active){
            titlescreen.draw(window);
        }
        else if(gameloopscreen.active){
            gameloopscreen.draw(window);
            window.draw(timer.timerText);
            int rand_chance = randomNumber(0, 100); //Returns a 1-100
            if(deerHit && rand_chance <= 1){    //on a 1/100 chance it sets the deer to a new position
                deerHit = false;    //Resets if it's been hit so that the deer is rendered again
                deer.newPosition(); //Sets a new random position for the deer
            }
            if(!deerHit){   //Renders the deer so long as it hasn't been shot
                deer.update(winSize);    //Function to update the deer. Thus far it only calls the moveDeer function.
                deer.renderTarget(window);  //Function to draw deer
                deerHit = deer.isHit(window);   //Checks if deer has been hit
                //Render deer dying and display that instead if the deer gets hit
            }
        }
        else if(gameOverScreen.active) gameOverScreen.draw(window);
        window.display();

    }

    return 0;
}