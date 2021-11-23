#pragma once
#include <sfml\Graphics.hpp>

class Enemy
{
#define MAX_NUMBER 20
public:
	sf::Sprite sprite;

	Enemy();

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

	void move(int n) {
		//prite.move(0, speed);
		if (n == 0) {
			sprite.move(-2, speed);
		}
		else if (n == 1)
		{
			sprite.move(2, speed + 1);
		}
		else if (n == 2)
		{
			sprite.move(0, speed);
		}
		else if (n == 3)
		{
			sprite.move(-3, speed + 2);
		}
		else {
			sprite.move(1, speed);
		}
	}

	void setDirection(int d) {
		direction = d;
	}

private:
	sf::Texture texture;
	float speed = 2;
	int direction = 0;

	bool isShoot = false;
	bool alive = false;
};

