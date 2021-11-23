#pragma once
#include <sfml\Graphics.hpp>

class Desktop
{
public:
	Desktop(float width, float height);
	~Desktop();

	void draw(sf::RenderWindow& window, int mode);

private:
    sf::Texture texture;
    sf::Sprite background;

};

