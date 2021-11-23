#pragma once
#include <sfml\Graphics.hpp>

class Bullet
{
public:
	sf::Sprite sprite;

	Bullet();
	void draw(sf::RenderWindow& window);
	void setPosition(int x, int y);
	void setShoot(bool shoot) {
		isShoot = shoot;
	}

	void setAlive(bool _alive) {
		alive = _alive;
	}

	bool isAlive() {
		return alive;
	}

private:
	sf::Texture texture;
	bool isShoot = false;
	bool alive = false;
};

