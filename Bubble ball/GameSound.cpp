#include "GameSound.h"

GameSound::~GameSound()
{

}

GameSound::GameSound(int no)
{

	if (!music.openFromFile("music1.ogg")) {
		//
	}

	//.. Monster die
	if (!buffer.loadFromFile("sound1.wav")) {
	}
	sound.setBuffer(buffer);

	//..Gift
	if (!buffer2.loadFromFile("sound2.wav")) {
	}
	sound2.setBuffer(buffer2);

	//.. Player die
	if (!buffer3.loadFromFile("sound4.wav")) {
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
