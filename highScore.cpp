/**
 * @file highScore.cpp
 * @author Sialas Tripp
 * @brief high score definition file
 * @date 2023-12-04
 * 
 */
#include "highScore.h"

/**
 * @brief default high score constuctor
 * 
 */
HighScore::HighScore(){
    mName = " ";
    mScore = 0;
}

/**
 * @brief high score constuctor for name and score given
 * 
 */
HighScore::HighScore(const std::string& name, int score){

    mName = name;
    mScore= score;
}

/**
 * @brief returns score 
 * 
 * @return int score
 */
int HighScore::getScore() const {
    return mScore;
}

/**
 * @brief returns name of player
 * 
 * @return std::string name of  player
 */
std::string HighScore::getName() const{
    return mName;
}