#pragma once
#include"Game.h"
class Menu
{
private:
	RenderWindow* window;
	Text menu[3];
	Font font;
	Sprite background;

public:
	Menu(RenderWindow* window, Font& font, ResourcesManager& resManager);
	~Menu();
	int getPressedItem();
	void Update();
	void Render();
};

