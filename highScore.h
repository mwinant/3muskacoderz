/**
 * @file highScore.h
 * @author Sialas
 * @brief high score header file
 * @date 2023-12-04
 * 
 */
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <SFML/Graphics.hpp>

class HighScore {
public:
    HighScore();
    HighScore(const std::string& name, int score);
    int getScore() const;
    std::string getName() const;
    
private:
    std::string mName;
    int mScore;
};
#endif