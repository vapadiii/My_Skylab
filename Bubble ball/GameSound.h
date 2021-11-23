#pragma once
#include <sfml\Graphics.hpp>
#include <sfml\Audio.hpp>
class GameSound
{
public:
	GameSound(int no);
	~GameSound();

	void play(int no);

private:
	sf::Music music;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::SoundBuffer buffer2;
	sf::Sound sound2;

	sf::SoundBuffer buffer3;
	sf::Sound sound3;
};

