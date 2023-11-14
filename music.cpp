#include "music.h"


Music::Music(){
    mMusic.openFromFile("sounds/intro.wav");
    mMusic.setVolume(100);
    mMusic.setLoop(true);
}
