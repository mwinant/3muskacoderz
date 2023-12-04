#include "highScoreManager.h"

HighScoreManager::HighScoreManager(){
    highScoreFile = "highscores.txt";
    maxHighScore = 5;
}

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

void HighScoreManager::updateHighScores(const HighScore& newScore) {
    std::vector<HighScore> highScores = loadHighScores();

    // Add the new score using push_back
    highScores.push_back(newScore);

    // Sort the high scores using the custom insertion sort
    highScores = insertionSort(highScores);

    // Keep only the top N high scores
    if (highScores.size() > maxHighScore) {
        highScores.resize(maxHighScore);
    }

    // Save the updated high scores
    saveHighScores(highScores);
}

void HighScoreManager::saveHighScores(const std::vector<HighScore>& highScores) {
    std::ofstream file(highScoreFile);
    if (file.is_open()) {
        for (const auto& score : highScores) {
            file << score.getName() << " " << score.getScore() << "\n";
        }

        file.close();
    }
}
