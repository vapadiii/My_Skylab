#pragma once
#include <sfml\Graphics.hpp>
//#include <sfml\Audio.hpp>
class GameSound
{
public:
	GameSound(float width, float height);
	~GameSound();

	void playMusic();

private:
	//sf::Music music;
	//sf::SoundBuffer buffer;
	//sf::Sound sound;
};

