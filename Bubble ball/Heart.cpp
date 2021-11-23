#include "Heart.h"
Heart::~Heart() {

}

Heart::Heart(float width, float height) {
    if (!texture.loadFromFile("images/heart.png")) {
        //
    }

    for (int i = 0; i < MAX_HEART; i++) {
        sprite[i].setTexture(texture);
        sprite[i].setPosition(20 + ( i * 40 ), 30);

        sprite[i].setScale(
            50 / sprite[i].getLocalBounds().width,
            50 / sprite[i].getLocalBounds().height);
    }
}

void Heart::draw(sf::RenderWindow& window) {
    for (int i = 0; i < numHeart; i++) {
        window.draw(sprite[i]);
    }
}

void Heart::initHeart() {
    numHeart = MAX_HEART;
}

void Heart::increase() {
    numHeart++;
}

void Heart::decrease() {
    numHeart--;
}

int Heart::getHeart() {
    return numHeart;
}

