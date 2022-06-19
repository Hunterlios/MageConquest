#pragma once
#include"Player.h"
class PlayerGUI
{
private:
	RenderWindow* window;
	Player* player;
	int score;

public:
	int hp;
	Text scoreText;
	RectangleShape hpBar, hpBarOutline;
	void Update();
	void Render();
	PlayerGUI(RenderWindow* window, Player* player, Font& font);
	~PlayerGUI();
};

