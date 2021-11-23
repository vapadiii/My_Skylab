#include "Menu.h"
Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("2005_iannnnnCPU.ttf"))
	{
		//handle eror
	}

	title.setFont(font);
	title.setCharacterSize(270); //setFontSize
	title.setFillColor(sf::Color::Blue);
	title.setString("SKYLAB");
	//gameOver.setOrigin(gameOver.getLocalBounds().width / 2, gameOver.getLocalBounds().height / 2); //setOrigin
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 4); //setOrigin
	title.setPosition(sf::Vector2f(width / 2, 10));

	menu[0].setFont(font);
	menu[0].setCharacterSize(100); //setFontSize
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("PLAY");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2); //setOrigin
	menu[0].setPosition(sf::Vector2f(width / 2, (height / MAX_ITEMS) + 50));

	menu[1].setFont(font);
	menu[1].setCharacterSize(100);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("LEADERBOARD");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, (height / MAX_ITEMS ) + 200));

	menu[2].setFont(font);
	menu[2].setCharacterSize(100);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("EXIT");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, (height / MAX_ITEMS ) + 350));

	myname.setFont(font);
	myname.setCharacterSize(50); //setFontSize
	myname.setFillColor(sf::Color::White);
	myname.setString("VIPADA  VARASAJJA   64010808");
	//gameOver.setOrigin(gameOver.getLocalBounds().width / 2, gameOver.getLocalBounds().height / 2); //setOrigin
	//myname.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 4); //setOrigin
	myname.setPosition(sf::Vector2f(40, 700));
}
Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	window.draw(title);
	window.draw(myname);
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItem + 1 < MAX_ITEMS)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
			selectedItem++;
			menu[selectedItem].setFillColor(sf::Color::Red);
	}
}
