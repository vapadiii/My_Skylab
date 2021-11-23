#include "Gift.h"
Gift::Gift() {
	if (!texture.loadFromFile("images/gift.png")) {
		//
	}


	sprite.setTexture(texture);
	//sprite.setPosition(100, 100);  //set positon x,y
	sprite.setScale(
		75 / sprite.getLocalBounds().width,
		55 / sprite.getLocalBounds().height);


	clock.restart();
	time = clock.getElapsedTime();
}

void Gift::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Gift::setPosition(float x, float y) {

	sprite.setPosition(x, y);
}

bool Gift::collision(sf::Sprite target) {
	if (sprite.getGlobalBounds().intersects(target.getGlobalBounds())) {
		//sprite.setColor(sf::Color::Transparent);
		return true;
	}
	else {
		return false;
	}
}

bool Gift::born() {



	float  num = time.asSeconds();
	//std::cout << time.asSeconds() << std::endl;

	if (num > 1) {
		num = 0;
		clock.restart();

		return true;
	}
	else {
		return false;
	
	}
}
