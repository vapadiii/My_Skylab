#include "Player.h"

Player::~Player() {

}

Player::Player(float width, float height) {

    sf::Vector2f targetSize(115.0f, 1150.0f);
    //sf::Sprite sprite;
    x = width;
    y = height;

    if (!texture.loadFromFile("images/rocket2.png")) {
        //
    }

    if (!texturebonus.loadFromFile("images/rr2.png")) {
        //
    }

    sprite.setTexture(texture);
    sprite.setPosition(576, 650);

    sprite.setScale(
        80 / sprite.getLocalBounds().width,
        80 / sprite.getLocalBounds().height);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::moveLeft() {
    if (sprite.getPosition().x > 0) {
        sprite.move(-speed, 0.0);
    }
}

void Player::moveRight() {
    if (sprite.getPosition().x < x-50) {
        sprite.move(speed, 0.0);
    }
}

void Player::moveUp() {
    if (sprite.getPosition().y > 0) {
        sprite.move(0.0, -speed);
    }
}

void Player::moveDown() {
    if (sprite.getPosition().y < y - 50) {
        sprite.move(0.0, speed);
    }
}

bool Player::collisionNew(sf::Sprite target) {
    if (sprite.getGlobalBounds().intersects(target.getGlobalBounds())) {
        //sprite.setColor(sf::Color::Transparent);
        return true;
    }
    else {
        return false;
    }
}

void Player::bonusTime(bool bonus) {
    this->bonus = bonus;
    if (bonus) {
        sprite.setTexture(texturebonus);
        sprite.setScale(
            200 / sprite.getLocalBounds().width,
            200 / sprite.getLocalBounds().height);
    }
    else {
        sprite.setTexture(texture);
        sprite.setScale(
            80 / sprite.getLocalBounds().width,
            80 / sprite.getLocalBounds().height);
    }
}

bool Player::isBonusTime() {
    return bonus;
}
