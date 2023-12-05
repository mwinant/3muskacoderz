/**
 * @file highScoreManager.cpp
 * @author Sialas Tripp
 * @brief high score manager function definition file
 * @date 2023-12-04
 * 
 */
#include "highScoreManager.h"

/**
 * @brief default high score manager constructor
 * 
 */
HighScoreManager::HighScoreManager(){
    highScoreFile = "highscores.txt";
    maxHighScore = 5;
}

/**
 * @brief uses insertion sort to sort all time high scores
 * 
 * @param highScores list of all top 5 high scores
 * @return std::vector<HighScore> sorted list of high scores
 */
std::vector<HighScore> HighScoreManager::insertionSort(const std::vector<HighScore>& highScores){
    std::vector<HighScore> sortedHighScores = highScores;
    for (size_t i = 1; i < sortedHighScores.size(); ++i) {
        HighScore key = sortedHighScores[i];
        int j = static_cast<int>(i) - 1;

        while (j >= 0 && sortedHighScores[j].getScore() < key.getScore()) {
            sortedHighScores[j + 1] = sortedHighScores[j];
            --j;
        }

        sortedHighScores[j + 1] = key;
    }

    return sortedHighScores;
}

/**
 * @brief loads file with previous high scores and loads them into a vector
 * 
 * @return std::vector<HighScore> the sorted vector of high scores
 */
std::vector<HighScore> HighScoreManager::loadHighScores() {
    std::vector<HighScore> highScores;
    std::ifstream file(highScoreFile);
    if (file.is_open()) {
        std::string name;
        int score;

        while (file >> name >> score) {
            highScores.emplace_back(name, score);
        }

        file.close();
    }

    // Sort high scores using insertion sort
    return insertionSort(highScores);
}

/**
 * @brief takes a new high score and adds it to file
 * 
 * @param newScore the new high score made by player
 */
void HighScoreManager::updateHighScores(const HighScore& newScore) {
    std::vector<HighScore> highScores = loadHighScores();

    // Add the new score using push_back
    highScores.push_back(newScore);

    // Sort the high scores using the custom insertion sort
    highScores = insertionSort(highScores);

    // Keep only the top 5 high scores
    if (highScores.size() > maxHighScore) {
        highScores.resize(maxHighScore);
    }

    // Save the updated high scores
    saveHighScores(highScores);
}

/**
 * @brief saves an score to high score txt file
 * 
 * @param highScores high score to be saved
 */
void HighScoreManager::saveHighScores(const std::vector<HighScore>& highScores) {
    std::ofstream file(highScoreFile);
    if (file.is_open()) {
        for (const auto& score : highScores) {
            file << score.getName() << " " << score.getScore() << "\n";
        }

        file.close();
    }
}
