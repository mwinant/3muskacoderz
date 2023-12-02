#include "highScore.h"

HighScore::HighScore(){
    mName = " ";
    mScore = 0;
}

HighScore::HighScore(const std::string& name, int score){

    mName = name;
    mScore= score;
}

int HighScore::getScore() const {
    return mScore;
}

std::string HighScore::getName() const{
    return mName;
}