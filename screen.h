#include <SFML/Graphics.hpp>
#include "background.h"
#include "coverArt.h"
#include "gameover.h"
#include "reticle.h"
#include "music.h"
#include "soundBuffer.h"
#include "sound.h"
#include "targets.h"
#include "extra.h"
#include "clock.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>

class Screen //helperClass
{
public:
    bool active = false;
    friend class Background;
    friend class CoverArt;
    friend class Reticle;
    friend class GameOver;
    friend class Deer;
    friend class Timer;
};

class TitleScreen : public Screen 
{
public:
    //main Screen items

    void draw(sf::RenderWindow &window)
    {
        Background background;
        Reticle reticle;
        CoverArt coverArt;
        window.draw(background.mSprite);
        window.draw(coverArt.deerSprite);
        window.draw(coverArt.text);
        window.draw(coverArt.text2);
        window.draw(reticle.mSprite);
    }
};

class GameLoopScreen : public Screen
{
public:
    //second Screen items
    void draw(sf::RenderWindow &window)
    {
        Background background2;
        // //window.draw(items);
        window.draw(background2.mSprite);
    }
};

class GameOverScreen : public Screen
{
public:
    //some Third screen items
    void draw(sf::RenderWindow &window)
    {   
        GameOver gameOver;
        //window.draw(items);
        window.draw(gameOver.sprite);
        window.draw(gameOver.sprite2);
        window.draw(gameOver.text);
    }
};