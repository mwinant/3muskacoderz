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
#include "highScore.h"
#include "highScoreManager.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>

int main()
{
    TitleScreen titlescreen;
    GameLoopScreen gameloopscreen;
    GameOverScreen gameOverScreen;
    gameOverGetNameScreen gameOverGetNameScreen;
    titlescreen.active=true; //sets titlescreen as first screen
    gameloopscreen.active=false;
    gameOverScreen.active=false;
    gameOverGetNameScreen.active=false;
    
    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Elk Hunter");
    sf::Vector2u winSize = window.getSize();
    Reticle reticle;
    Music music;
    SoundBuffer buffer;
    Sound sound(buffer);
    Deer deer, deer1, deer2, deer3, deer4;
    Timer timer;
    Score score;
    HighScoreManager highScoreManager;
    bool highScoresUpdated = false;


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
    int hitTimer = 0,
        hitTimer1 = 0,
        hitTimer2 = 0,
        hitTimer3 = 0,
        hitTimer4 = 0;

    // hides system mouse cursor
    window.setMouseCursorVisible(false);
    
    //play music
    music.mMusic.play();
    std::string playerName;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                if (titlescreen.active) {
                    // Close cover screen and start game
                    gameloopscreen.active = true;
                    titlescreen.active = false;
                    countdown = 30;
                } 
                else if (gameOverGetNameScreen.active) {
                    // Switch to the game over screen
                    gameOverScreen.active = true;
                    gameOverGetNameScreen.active = false;
                }
            }

            // Mouse button pressed: play the sound
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sound.mSound.play();
            }

            // Get user input for name
            if (event.type == sf::Event::TextEntered && gameOverGetNameScreen.active) {
                
                // if entered key is pressed, go to game over screen
                if (event.text.unicode == 13) {  
                    gameOverScreen.active = true;
                    gameOverGetNameScreen.active = false;
                }

                // else if a normal key that's not back space is pressed, assign it to player name
                else if (event.text.unicode < 128 && event.text.unicode != 8) {
                    playerName += static_cast<char>(event.text.unicode);
                }

                // else if backspace is pressed, remove last character
                else if (event.text.unicode == 8 && !playerName.empty()) {
                    playerName.pop_back(); 
                }
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
        if(countdown<=-1 &&  gameloopscreen.active == true){
            gameloopscreen.active=false;
            gameOverGetNameScreen.active=true;
            // gameOverScreen.active=true;   
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

            // deer.hitMarker(window, score, winSize);
            // deer1.hitMarker(window, score, winSize);
            // deer2.hitMarker(window, score, winSize);
            // deer3.hitMarker(window, score, winSize);
            // deer4.hitMarker(window, score, winSize);

            if(hitTimer > 0){   //Displays the "HIT!" text so long as the hit timer is above 0.
                deer.renderHitText(window);
                hitTimer--;
                deer.gameLoop(window, score, winSize);
            }else{  //Renders Deer
                hitTimer = deer.gameLoop(window, score, winSize);
            }   
            if(hitTimer1 > 0){   //Displays the "HIT!" text so long as the hit timer is above 0.
                deer1.renderHitText(window);
                hitTimer1--;
                deer1.gameLoop(window, score, winSize);
            }else{  //Renders Deer
                hitTimer1 = deer1.gameLoop(window, score, winSize);
            }
            if(hitTimer2 > 0){   //Displays the "HIT!" text so long as the hit timer is above 0.
                deer2.renderHitText(window);
                hitTimer2--;
                deer2.gameLoop(window, score, winSize);
            }else{  //Renders Deer
                hitTimer2 = deer2.gameLoop(window, score, winSize);
            }   
            if(hitTimer3 > 0){   //Displays the "HIT!" text so long as the hit timer is above 0.
                deer3.renderHitText(window);
                hitTimer3--;
                deer3.gameLoop(window, score, winSize);
            }else{  //Renders Deer
                hitTimer3 = deer3.gameLoop(window, score, winSize);
            }
            if(hitTimer4 > 0){   //Displays the "HIT!" text so long as the hit timer is above 0.
                deer4.renderHitText(window);
                hitTimer4--;
                deer4.gameLoop(window, score, winSize);
            }else{  //Renders Deer
                hitTimer4 = deer4.gameLoop(window, score, winSize);
            }
            
            
            // deer1.gameLoop(window, score, winSize);
            //     deer2.gameLoop(window, score, winSize);
            //     deer3.gameLoop(window, score, winSize);
            //     deer4.gameLoop(window, score, winSize);
            // else{   //Renders Deer
                
            //     hitTimer1 = deer1.gameLoop(window, score, winSize);
            //     hitTimer2 = deer2.gameLoop(window, score, winSize);
            //     hitTimer3 = deer3.gameLoop(window, score, winSize);
            //     hitTimer4 = deer4.gameLoop(window, score, winSize);
            // }

            //Takes position of mouse and draws the reticle over it.
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            reticle.mSprite.setPosition(static_cast<sf::Vector2f>(mousePosition));
            reticle.renderReticle(window);
        }
        else if (gameOverGetNameScreen.active) {
            // Draw the rest of the gameOverGetNameScreen
            window.clear();
            gameOverGetNameScreen.draw(window);
            gameOverGetNameScreen.getName.namePromptText.setString("Enter your name: " + playerName);
            window.display();
        }
        else if (gameOverScreen.active) {
            window.clear();
            gameOverScreen.draw(window);
            score.changePosition(400, 150);
            score.changeSize(70);
            score.renderEndScore(window);

            // Update high scores only once
            if (!highScoresUpdated) {
                HighScore newHighScore(playerName, score.getScore());
                highScoreManager.updateHighScores(newHighScore);
                highScoresUpdated = true;
            }

            // Load and display high scores
            std::vector<HighScore> loadedHighScores = highScoreManager.loadHighScores();

            sf::Font font;
            if (!font.loadFromFile("images/scoreFont.ttf")) {
                std::cout<<"Error loading high score image\n";
            }

            sf::Text highScoresText;
            highScoresText.setFont(font);
            highScoresText.setCharacterSize(50);
            highScoresText.setPosition(50, 150);

            std::string highScoresString = "Top 5 High Scores:\n";
            size_t count = 0;
            for (const auto& score : loadedHighScores) {
                highScoresString += score.getName() + ": " + std::to_string(score.getScore()) + "\n";
                count++;
                if (count >= 5) {
                    break;
                }
            }

            highScoresText.setString(highScoresString);

            window.draw(highScoresText);
        }

        window.display();
    }
    return 0;
}