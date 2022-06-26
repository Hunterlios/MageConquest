#pragma once
#include"Game.h"
class Help : public State
{
	RenderWindow* window;
	Text help[3];
	Font font;
	Sprite background;

public:
	Help(RenderWindow* window, Font& font, ResourcesManager& resManager);
	~Help();
	int getPressedItem();
	void Update(float& deltaTime);
	void Render();
};

