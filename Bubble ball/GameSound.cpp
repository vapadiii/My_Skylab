#include "GameSound.h"

GameSound::~GameSound()
{

}

GameSound::GameSound(int no)
{

	if (!music.openFromFile("music1.ogg")) {
		//
	}


	if (!buffer.loadFromFile("sound1.wav")) {
	}
	sound.setBuffer(buffer);

	if (!buffer2.loadFromFile("sound2.wav")) {
	}
	sound2.setBuffer(buffer2);


	if (!buffer3.loadFromFile("sound3.wav")) {
	}
	sound3.setBuffer(buffer3);

	
}

void GameSound::play(int no)
{
	if (no == 1) {
		sound.play();
	}
	if (no == 2) {
		sound2.play();
	}
	if (no == 3) {
		sound3.play();
	}
	//music.play();
}
