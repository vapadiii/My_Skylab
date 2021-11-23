#include "Leaderboard.h"
using namespace std;
Leaderboard::Leaderboard(float width, float height)
{
	if (!font.loadFromFile("2005_iannnnnCPU.ttf"))
	{
		//handle eror
	}
	leaderboard.setFont(font);
	leaderboard.setCharacterSize(100); //setFontSize
	leaderboard.setFillColor(sf::Color::Yellow);
	leaderboard.setString("LEADERBOARD");
	leaderboard.setOrigin(leaderboard.getLocalBounds().width / 2, leaderboard.getLocalBounds().height / 2); //setOrigin
	leaderboard.setPosition(sf::Vector2f(width / 2, 100));

	for (int i = 0; i < 5; i++) {
		player[i].setFont(font);
		player[i].setCharacterSize(80); //setFontSize
		player[i].setFillColor(sf::Color::Magenta);
		player[i].setString("Play1");
		//player1.setOrigin(player1.getLocalBounds().width / 2, player1.getLocalBounds().height / 2); //setOrigin
		player[i].setPosition(sf::Vector2f((width / 2) - 250, 200 + (100*i)));
	}

	for (int i = 0; i < 5; i++) {
		score[i].setFont(font);
		score[i].setCharacterSize(80); //setFontSize
		score[i].setFillColor(sf::Color::Magenta);
		score[i].setString("Play1");
		//player1.setOrigin(player1.getLocalBounds().width / 2, player1.getLocalBounds().height / 2); //setOrigin
		score[i].setPosition(sf::Vector2f((width / 2) + 150, 200 + (100 * i)));
	}

	back.setFont(font);
	back.setCharacterSize(50); //setFontSize
	back.setFillColor(sf::Color::White);
	back.setString("press ENTER for back");
	//gameOver.setOrigin(gameOver.getLocalBounds().width / 2, gameOver.getLocalBounds().height / 2); //setOrigin
	//myname.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 4); //setOrigin
	back.setPosition(sf::Vector2f(40, 700));

	openfile();

}
Leaderboard::~Leaderboard()
{

}

void Leaderboard::draw(sf::RenderWindow& window)
{
	window.draw(leaderboard);
	window.draw(back);
	for (int i = 0; i < 5; i++) {
		window.draw(player[i]);
		window.draw(score[i]);
	}
	//window.draw(score1);
	//window.draw(player2);
	///window.draw(score2);
}

void Leaderboard::saveScore(std::string name, int score) {
	/*
	leader[4].name = name;
	leader[4].score = score;
	std::cout << leader[4].name << std::endl;
	std::cout << leader[4].score << std::endl;
	*/
	Leader temp[5];

	int rank = 0;
	bool newRank = false;
	// safe old score
	for (int i = 0; i < 5; i++) {
		temp[i] = leader[i];
	}

	// check ranking
	for(int i=0; i<5; i++) {
		if (score > leader[i].score) {
			rank = i;
			newRank = true;
			//leader[i].name = name;
			//leader[i].score = score;
			break;
		}
	}

	if (newRank) {
		for (int i = 0; i < rank; i++) {
			leader[i] = temp[i];
		}

		leader[rank].name = name;
		leader[rank].score = score;

		for (int i = rank; i < 4; i++) {
			leader[i + 1] = temp[i];
		}
	}

	std::cout << rank << std::endl;
	savefile();
	openfile();

}

void Leaderboard::savefile() {
	std::ofstream fout("score.txt");

	if (!fout.fail())
	{
		for (int i = 0; i < 5; i++)
		{
			fout << leader[i].name << endl;
			fout << leader[i].score << endl;
		}
		fout.close();
	}
}

void Leaderboard::openfile() {

	/*
	std::string myText;
	std::ifstream MyReadFile("score.txt");

	sf::String name;

	int i = 0;
	while (std::getline(MyReadFile, myText)) {
		//std::cout << myText << std::endl;
		player[i].setString(myText);
		i++;
		if (i >= 5) {
			break;
		}
	}
	MyReadFile.close();
	*/

	std::ifstream fin;
	fin.open("score.txt");
	if (!fin.fail())
	{
		for (int i = 0; i < 5; i++)
		{
			string name, scoreString;

			getline(fin, name);
			getline(fin, scoreString);
			leader[i].name = name;
			leader[i].score = atoi(scoreString.c_str());

			player[i].setString(name);
			score[i].setString(scoreString);
			//cout << a[i].name << "";
			//cout << a[i].score << endl;
		}
		fin.close();
	}
}
