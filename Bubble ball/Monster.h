#pragma once
#include <sfml\Graphics.hpp>
#define MAX_ITEMS 10 
class Monster
{
public:
	Monster(float width, float height);
	~Monster();

	void draw(sf::RenderWindow& window);
	void destroy(sf::RenderWindow& window, int score);
	sf::Sprite sMonster[MAX_ITEMS];

	void create(sf::Texture texture);

private:
	sf::Texture monster;
	sf::Texture monsterBoss;
	
	sf::Texture texture;
	sf::Sprite sprite;
};

