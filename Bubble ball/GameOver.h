#pragma once
#include <sfml\Graphics.hpp>

class GameOver
{
public:
	GameOver(float width, float height);
	~GameOver();

	void draw(sf::RenderWindow& window);
	void setPlayerName(std::string name);
		

private:
	sf::Font font;
	sf::Text gameOver;
	sf::Text playerName;
	sf::Text ch[6];
	sf::RectangleShape shape;
	sf::Text back;
};

