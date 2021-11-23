#pragma once
#include <sfml\Graphics.hpp>
#include <iostream>
#include <fstream>
struct Leader {
	std::string name;
	int score;

};

class Leaderboard
{
public:
	Leaderboard(float width, float height);
	~Leaderboard();

	void draw(sf::RenderWindow& window);
	void openfile();
	void savefile();
	void saveScore(std::string name, int score);


private:
	sf::Font font;
	sf::Text leaderboard;
	sf::Text player[5];
	sf::Text score[5];
	Leader leader[5];
	sf::Text back;

};

