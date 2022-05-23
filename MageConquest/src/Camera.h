#pragma once
#include"pch.h"
#include"Player.h"
class Camera
{
private:
	RenderWindow* window;
	View view;
	Player* player;

public:
	void Update();
	void Render();
	Camera(RenderWindow* window, Player* player);
	~Camera();
};

