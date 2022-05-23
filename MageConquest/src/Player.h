#pragma once
#include"pch.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	float ms = 150.f;
public:
	RectangleShape getShape();
	void Update(float deltaTime);
	void Render();
	Player(RenderWindow* window);
	~Player();
	
};

