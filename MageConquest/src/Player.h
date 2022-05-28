#pragma once
#include"pch.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;

public:
	RectangleShape getShape();
	void Update(float deltaTime);
	void Render();
	Player(RenderWindow* window);
	~Player();
	
};

