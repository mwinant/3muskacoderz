/**
 * @file main.cpp
 * @author Mikayla, Justin, Silas
 * @brief 
 * @version 0.1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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
#include "score.h"
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
    gameloopscreen.active=false;
    gameOverScreen.active=false;
    
    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Elk Hunter");
    sf::Vector2u winSize = window.getSize();
    Reticle reticle;
    Music music;
    SoundBuffer buffer;
    Sound sound(buffer);
    Deer deer, deer1, deer2, deer3, deer4;
    Timer timer;
    Score score;

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

    //Allows the "HIT!" text to stay on screen for a consistent amount of time
    int hitTimer = 0;

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
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                score.addShot();
            }
            gameloopscreen.draw(window);
            window.draw(timer.timerText);
            score.renderScore(window);  //Calls function from class to render the score
            if(hitTimer > 0){   //Displays the "HIT!" text so long as the hit timer is above 0.
                deer.renderHitText(window);
                hitTimer--;
                deer.gameLoop(window, score, winSize);
                deer1.gameLoop(window, score, winSize);
                deer2.gameLoop(window, score, winSize);
                deer3.gameLoop(window, score, winSize);
                deer4.gameLoop(window, score, winSize);
            } 
            else{   //Renders Deer
                hitTimer = deer.gameLoop(window, score, winSize);
                hitTimer = deer1.gameLoop(window, score, winSize);
                hitTimer = deer2.gameLoop(window, score, winSize);
                hitTimer = deer3.gameLoop(window, score, winSize);
                hitTimer = deer4.gameLoop(window, score, winSize);
            }

            //Takes position of mouse and draws the reticle over it.
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            reticle.mSprite.setPosition(static_cast<sf::Vector2f>(mousePosition));
            reticle.renderReticle(window);
        }
        else if(gameOverScreen.active){
            gameOverScreen.draw(window);
            score.changePosition(220, 220);
            score.changeSize(70);
            score.renderEndScore(window);
        } 
        window.display();

    }

    return 0;
}