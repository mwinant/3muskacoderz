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
    scoreText.setString(std::to_string(score));
    scoreNameText.setString("Score:");
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