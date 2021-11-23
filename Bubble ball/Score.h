#pragma once
#include <sfml\Graphics.hpp>

class Score
{
public:
	Score();

	void draw(sf::RenderWindow& window, int score);


private:
	int point = 0;
	sf::Font font;
	sf::Text txt;
};

