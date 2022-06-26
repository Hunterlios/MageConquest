#pragma once
#include"State.h"
#include"Game.h"
class GameOver : public State
{
private:
	RenderWindow* window;
	Text text[2];
	Sprite background;
	int highestPoints;
	ofstream highscoreWrite;
	ifstream highscoreRead;

public:

	GameOver(RenderWindow* window, Font& font, ResourcesManager& resManager, int score);
	virtual ~GameOver();
	int getPressedItem();
	void Update(float& deltaTime);
	void Render();
};

