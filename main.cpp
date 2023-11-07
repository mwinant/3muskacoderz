#include <SFML/Graphics.hpp>
#include "background.h"
#include "targets.h"
#include "extra.h"


int main()
{

    sf::RenderWindow window(sf::VideoMode(640, 480), "Big Buck Hunter");
    Background background;
    Deer deer;
    // hides system mouse cursor
    window.setMouseCursorVisible(false);

    
    //change the mouse cursor to reticle
    sf::Texture texture;
    texture.loadFromFile("images/reticle.png");
    sf::Sprite reticle(texture);
    reticle.setOrigin(reticle.getLocalBounds().width / 2, reticle.getLocalBounds().height / 2);

    // sets scale of reticle to be smaller
    float scaleFactor = .25f; 
    reticle.setScale(scaleFactor, scaleFactor);
    bool deerHit = false; //Checks if the deer has been hit. Temporary
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        reticle.setPosition(static_cast<sf::Vector2f>(mousePosition));

        window.clear();
        window.draw(background.mSprite);

        int rand_chance = randomNumber(0, 100); //Returns a 1-100
        if(deerHit && rand_chance <= 1){    //on a 1/100 chance it sets the deer to a new position
            deerHit = false;    //Resets if it's been hit so that the deer is rendered again
            deer.newPosition(); //Sets a new random position for the deer
        }
        if(!deerHit){   //Renders the deer so long as it hasn't been shot
            deer.renderTarget(window);  //Function to draw deer
            deerHit = deer.isHit(window);   //Checks if deer has been hit
            //Render deer dying and display that instead if the deer gets hit
        }
        
        window.draw(reticle);
        window.display();
    }

    return 0;
}