#include "GameOver.h"
GameOver::GameOver(float width, float height)
{
	if (!font.loadFromFile("2005_iannnnnCPU.ttf"))
	{
		//handle eror
	}
	gameOver.setFont(font);
	gameOver.setCharacterSize(100); //setFontSize
	gameOver.setFillColor(sf::Color::Blue);
	gameOver.setString("GAME OVER");
	//gameOver.setOrigin(gameOver.getLocalBounds().width / 2, gameOver.getLocalBounds().height / 2); //setOrigin
	gameOver.setOrigin(gameOver.getLocalBounds().width / 2, gameOver.getLocalBounds().height / 4); //setOrigin
	gameOver.setPosition(sf::Vector2f(width / 2, height / 4));

	playerName.setFont(font);
	playerName.setCharacterSize(100); //setFontSize
	playerName.setFillColor(sf::Color::Blue);
	playerName.setString("");
	//playerName.setOrigin(playerName.getLocalBounds().width / 2, playerName.getLocalBounds().height / 2); //setOrigin
	playerName.setPosition(sf::Vector2f(width / 2, 370));

	shape.setFillColor(sf::Color::Red);
	shape.setSize(sf::Vector2f(250, 20));
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2); //setOrigin
	shape.setPosition(sf::Vector2f(width / 2, 500));


	back.setFont(font);
	back.setCharacterSize(50); //setFontSize
	back.setFillColor(sf::Color::White);
	back.setString("press ENTER for menu");
	back.setPosition(sf::Vector2f(40, 700));

}
GameOver::~GameOver()
{

}

void GameOver::draw(sf::RenderWindow& window)
{
	window.draw(gameOver);
	window.draw(playerName);
	window.draw(back);
	window.draw(shape);
}

void GameOver::setPlayerName(std::string name) {
	playerName.setString(name);
	playerName.setOrigin(playerName.getLocalBounds().width / 2, playerName.getLocalBounds().height / 2); //setOrigin
}
