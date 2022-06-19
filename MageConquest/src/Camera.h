#pragma once
#include"PlayerGUI.h"

class Camera
{
private:
	RenderWindow* window;
	View view;
	Player* player;
	PlayerGUI* playerGUI;

public:
	void Update();
	void Render();
	Camera(RenderWindow* window, Player* player, PlayerGUI* playerGUI);
	~Camera();
};

