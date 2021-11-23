#include "Enemy.h"
Enemy::Enemy() {
	if (!texture.loadFromFile("images/enemy1.png")) {
		//
	}

	
	sprite.setTexture(texture);
	//sprite.setPosition(100, 100);  //set positon x,y
	sprite.setScale(
		75 / sprite.getLocalBounds().width,
		55 / sprite.getLocalBounds().height);
		
	
}

void Enemy::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Enemy::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

bool Enemy::collision(sf::Sprite target) {
	if (sprite.getGlobalBounds().intersects(target.getGlobalBounds())) {
		//sprite.setColor(sf::Color::Transparent);
		return true;
	}
	else {
		return false;
	}
}


