#include "extra.h"


int randomNumber(int min, int max){
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    int rand_int = distribution(gen);
    return rand_int;
}