/**
 * @file score.h
 * @author Justin Bradshaw
 * @brief Holds the score class for the game. Also counts the number of hits in the class.
 * @version 0.1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>


class Score{
public:
    Score();
    ~Score(){};
    void updateScore(int amount);
    void renderScore(sf::RenderWindow& window);
    void renderEndScore(sf::RenderWindow& window);
    void changePosition(int x, int y);
    void changeSize(int size);
    void addShot();
    
private:
    sf::Text scoreText;
    sf::Font scoreFont;
    sf::Text scoreNameText;
    sf::Font scoreNameFont;
    sf::Text hitsText;
    sf::Text numHitsText;
    sf::Text shotsText;
    sf::Text numShotsText;
    int score,  //Keeps track of score
        hits,   //Keeps track of how many hits
        shots;  //Keeps track of how many shots
};


#endif