#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>


class Score{
public:
    Score();
    ~Score(){};
    void updateScore(int amount);
    void renderScore(sf::RenderWindow& window);
    
private:
    sf::Text scoreText;
    sf::Font scoreFont;
    sf::Text scoreNameText;
    sf::Font scoreNameFont;
    int score;
    int hits;
};


#endif