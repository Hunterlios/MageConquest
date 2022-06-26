#pragma once
#include"Game.h"
#include"Help.h"
#include"GameOver.h"
#include"State.h"
class Menu : public State
{
private:
	RenderWindow* window;
	Text menu[3];
	Sprite background;

public:
	Menu(RenderWindow* window, Font& font, ResourcesManager& resManager);
	virtual ~Menu();
	int getPressedItem();
	void Update(float& deltaTime);
	void Render();
};

