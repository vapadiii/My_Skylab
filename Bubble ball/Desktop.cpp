#include "Desktop.h"

Desktop::~Desktop() {
}

float scaleX;
float scaleY;
Desktop::Desktop(float width, float height) {
    sf::Vector2f targetSize(1024.0f, 720.0f);
    sf::Vector2f windowSize(width, height);
    sf::Vector2f textureSize;;

    scaleX = 100.f;
    scaleY = 100.f;
  
}

void Desktop::draw(sf::RenderWindow& window, int mode) {

    if (mode == 1) {
        
        if (!texture.loadFromFile("images/introblack.JPG")) {
            //handle error
        }
        
    }

    if (mode == 2) {
        if (!texture.loadFromFile("playpage.jpg")) {         
            //handle error
        }
    }
    
    background.setTexture(texture);
    background.setScale(
        window.getSize().x / background.getLocalBounds().width,
        window.getSize().y / background.getLocalBounds().height);

    window.draw(background);
}
