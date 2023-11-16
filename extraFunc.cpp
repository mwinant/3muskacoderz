/**
 * @file extraFunc.cpp
 * @author Justin Bradshaw
 * @brief Holds the extra functions for the game
 * @version 0.1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "extra.h"

/**
 * @brief Returns a randomly generated number between min and max
 * 
 * @param min the minimum number it can return
 * @param max the maximum number it can return
 * @return int the number it returns
 */
int randomNumber(int min, int max){
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    int rand_int = distribution(gen);
    return rand_int;
}