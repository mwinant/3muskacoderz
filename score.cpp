/**
 * @file score.cpp
 * @author Justin Bradshaw
 * @brief A file that contains the constructor and functions for the class Score. This renders the score and keeps track of it throughout the game.
 * @version 0.1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "score.h"

/**
 * @brief Construct a new Score:: Score object
 * 
 */
Score::Score(){
    scoreFont.loadFromFile("images/timerfont.ttf");
    scoreText.setFont(scoreFont);
    scoreText.setPosition(550,5); 
    scoreText.setCharacterSize(40);
    scoreNameFont.loadFromFile("images/scoreFont.ttf");
    scoreNameText.setFont(scoreNameFont);
    scoreNameText.setPosition(475,3);
    scoreNameText.setCharacterSize(40);
    score = 0;
    hits = 0;
    shots = 0;
    scoreText.setString(std::to_string(score));
    scoreNameText.setString("Score:");

    hitsText.setFont(scoreNameFont);
    hitsText.setPosition(220, 280);
    hitsText.setCharacterSize(70);
    hitsText.setString("Hits:");

    numHitsText.setFont(scoreFont);
    numHitsText.setPosition(360, 282);
    numHitsText.setCharacterSize(70);

    shotsText.setFont(scoreNameFont);
    shotsText.setPosition(220, 340);
    shotsText.setCharacterSize(70);
    shotsText.setString("Shots:");

    numShotsText.setFont(scoreFont);
    numShotsText.setPosition(360, 342);
    numShotsText.setCharacterSize(70);

}

/**
 * @brief Updates the score by whatever amount is passed to it
 * 
 * @param amount The amount the score will be updated by
 */
void Score::updateScore(int amount){
    score = score + amount;
    hits++;
    scoreText.setString(std::to_string(score));
    numHitsText.setString(std::to_string(hits));
}

/**
 * @brief Renders the score in the window
 * 
 * @param window the game window that was created in main.cpp
 */
void Score::renderScore(sf::RenderWindow& window){
    window.draw(scoreText);
    window.draw(scoreNameText);
}


void Score::renderEndScore(sf::RenderWindow& window){
    window.draw(scoreText);
    window.draw(scoreNameText);
    window.draw(hitsText);
    window.draw(numHitsText);
    window.draw(shotsText);
    window.draw(numShotsText);
}

/**
 * @brief Changes the position of the score text
 * 
 * @param x x axis position
 * @param y y axis position
 */
void Score::changePosition(int x, int y){
    scoreNameText.setPosition(x,y);
    scoreText.setPosition(x+140, y+2);
}

/**
 * @brief Changes the character size of the score text
 * 
 * @param size size that it is being changed to
 */
void Score::changeSize(int size){
    scoreNameText.setCharacterSize(size);
    scoreText.setCharacterSize(size);
}

/**
 * @brief Counts the number of times the player shoots
 * 
 */
void Score::addShot(){
    shots++;
    numShotsText.setString(std::to_string(shots));
}