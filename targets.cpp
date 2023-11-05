#include "targets.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 */
Deer::Deer(){
    mTexture.loadFromFile("images/PIX_deer_upright.png");
    mDeer.setTexture(mTexture);
    mDeer.setPosition(550,300);
    mDeer.setScale(.1f, .1f);
    //mIncrement = sf::Vector2i(1, 1);
}


// void Deer::renderTarget(sf::RenderWindow window){
//     window.draw(mDeer);
// }




/**
 * @brief Handle events from input devices and the window
 * 
 */
// void Deer::handleInput()
// {
//     sf::Event event;
//     while(mWindow.pollEvent(event))
//     {
//         if(event.type == sf::Event::Closed)
//         {
//             // Close window button clicked.
//             mWindow.close();
//         }
//     }
// }

/**
 * @brief Update objects in the scene
 * 
 */
// void Deer::update()
// {
//     moveCherry();
// }

/**
 * @brief Moves the cherry to update the scene. Calculates the direction to move the cherry
 * 
 */
// void Deer::moveCherry()
// {
//     sf::Vector2u winSize = mWindow.getSize();
//     int cherryX = 62;
//     int cherryY = 62;
//     if ((mDeer.getPosition().x + (cherryX / 2) > winSize.x && mIncrement.x > 0) ||
//     (mDeer.getPosition().x - (cherryX / 2) < 0 && mIncrement.x < 0))
//     {
//         // Reverse the direction on X axis
//         mIncrement.x = -mIncrement.x;
//     }
//     if ((mDeer.getPosition().y + (cherryY / 2) > winSize.y && mIncrement.y > 0) ||
//     (mDeer.getPosition().y - (cherryY / 2) < 0 && mIncrement.y < 0))
//     {
//         // Reverse the direction on Y axis.
//         mIncrement.y = -mIncrement.y;
//     }
//     mDeer.setPosition(
//         mDeer.getPosition().x + mIncrement.x,
//         mDeer.getPosition().y + mIncrement.y);
// }


