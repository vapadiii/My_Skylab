#pragma once
#include <sfml\Graphics.hpp>
#define MAX_HEART 3
class Heart
{
public:
	Heart(float width, float height);
	~Heart();

	void draw(sf::RenderWindow& window);

	void initHeart();
	void increase();
	void decrease();
	int getHeart();


private:
	sf::Texture texture;
	sf::Sprite sprite[3];
	int numHeart = MAX_HEART;

};

