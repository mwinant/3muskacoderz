/**
 * @file highScoreManager.h
 * @author Sialas Tripp
 * @brief  high score manager header file
 * @date 2023-12-04
 * 
 */
#include <vector>
#include <fstream>
#include <iostream>
#include "highScore.h" 

class HighScoreManager {
public:
    HighScoreManager();
    std::vector<HighScore> loadHighScores();
    void updateHighScores(const HighScore& newScore);
    void saveHighScores(const std::vector<HighScore>& highScores);
    std::vector<HighScore> insertionSort(const std::vector<HighScore>& highScores);

private:
    std::string highScoreFile;
    size_t maxHighScore;
};