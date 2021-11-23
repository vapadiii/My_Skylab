#pragma once
#include <sfml\Graphics.hpp>

class Player
{
public:
	Player(float width, float height);
	~Player();

	void draw(sf::RenderWindow& window);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void shoot();
	void collision(sf::Sprite target);
	bool collisionNew(sf::Sprite target);

	void setAlive(bool isAlive) {
		alive = isAlive;
	}

	bool isAlive() {
		return alive;
	}

	sf::Vector2f getPosition() {
		return sprite.getPosition();
	}

	void setPosition(float x, float y) {
		sprite.setPosition(x, y);
	}

	void bonusTime(bool bonus);

	bool isBonusTime();

private:
	sf::Texture texture;
	sf::Texture texturebonus;
	sf::Sprite sprite;
	sf::Vector2f position;
	float speed = 7;
	bool alive = true;
	float x;
	float y;
	bool bonus = false;
};

