#include "Score.h"


Score::Score() {

	if (!font.loadFromFile("2005_iannnnnCPU.ttf"))
	{
		//handle eror
	}
	txt.setFont(font);
	txt.setCharacterSize(70); //setFontSize
	txt.setFillColor(sf::Color::Red);
	//txt.setOrigin(txt.getLocalBounds().width / 2, txt.getLocalBounds().height / 2); //setOrigin
	txt.setPosition(900, 0);
}


void Score::draw(sf::RenderWindow& window, int point) {
	txt.setString("Score : " + std::to_string(point));
    window.draw(txt);
}