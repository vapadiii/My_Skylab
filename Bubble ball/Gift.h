#pragma once
#include <sfml\Graphics.hpp>
class Gift
{
public:
	sf::Sprite sprite;

	Gift();

	void draw(sf::RenderWindow& window);
	void setPosition(float x, float y);
	bool collision(sf::Sprite target);


	void setShoot(bool shoot) {
		isShoot = shoot;
	}

	void setAlive(bool alive) {
		this->alive = alive;
	}

	bool isAlive() {
		return alive;
	}

	void move() {
		sprite.move(0, speed);
	}

	bool born();

private:
	sf::Texture texture;
	float speed = 2;

	bool isShoot = false;
	bool alive = false;
	sf::Clock clock;
	sf::Time time;
};

