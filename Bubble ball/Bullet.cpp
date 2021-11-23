#include "Bullet.h"


Bullet::Bullet() {
   
    sf::Vector2f targetSize(20.0f, 20.0f);

    texture.loadFromFile("images/bullet.png");
    sprite.setTexture(texture);

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width,
        targetSize.y / sprite.getLocalBounds().height);
       
    sprite.setPosition(200,200);
}

void Bullet::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
