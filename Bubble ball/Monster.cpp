#include "Monster.h"
Monster::~Monster() {
}

Monster::Monster(float width, float height) {

	sf::Vector2f targetSize(100.0f, 100.0f);
	sf::Sprite sprite;
	

	monster.loadFromFile("images/monster1.png");
	sprite.setTexture(monster);

	sMonster[0].setTexture(monster);
	sMonster[0].setPosition(100 , 100);  //set positon x,y
	sMonster[0].setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);

	sMonster[1].setTexture(monster);
	sMonster[1].setPosition(200, 100);  //set positon x,y
	sMonster[1].setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);
	
	sMonster[2].setTexture(monster);
	sMonster[2].setPosition(600, 100);  //set positon x,y
	sMonster[2].setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);
	
	/*
	monsterBoss.loadFromFile("images/monster2.jpg");
	spriteBoss.setTexture(monsterBoss);
	sMonster[2].setTexture(monsterBoss);
	sMonster[2].setPosition(600, 100);  //set positon x,y
	sMonster[2].setScale(
		targetSize.x / sprite.getLocalBounds().width,
		targetSize.y / sprite.getLocalBounds().height);


	*/

	/*
	for (int i = 0; i < MAX_ITEMS; i++) {
		sMonster[i].setTexture(monster);
		sMonster[i].setPosition(100 + (70*i), 100);  //set center positon
		sMonster[i].setScale(
			targetSize.x / sprite.getLocalBounds().width,
			targetSize.y / sprite.getLocalBounds().height);
	}
	*/
	

}

void Monster::create(sf::Texture texture) {
	sprite.setTexture(texture);
}

void Monster::draw(sf::RenderWindow& window)
{
	/*
	sf::Texture texture;
	if (!texture.loadFromFile("images/paddle1.png")) {
		//handle error
	}
	sf::Sprite monster;
	monster.setTexture(texture);
	*/

	window.draw(sMonster[0]);
	window.draw(sMonster[1]);
	window.draw(sMonster[2]);

	/*
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(sMonster[i]);
	}
	*/
	
}

void Monster::destroy(sf::RenderWindow& window, int score)
{


	if (score == 10) {
		sMonster[2].setColor(sf::Color::Transparent);
	}
	if (score == 20) {
		sMonster[1].setColor(sf::Color::Transparent);
	}
	if (score == 40) {
		//sMonster[0].setColor(sf::Color::Transparent);
	}


	if (score == -10) {
		sMonster[2].setColor(sf::Color::White);
	}
	if (score == -20) {
		sMonster[1].setColor(sf::Color::White);
	}
	if (score == -40) {
		//sMonster[0].setColor(sf::Color::White);
	}
}


