#pragma once
#include"pch.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	Texture* pTexture;

public:
	RectangleShape getShape();
	void Update(float deltaTime);
	void Render();
	Player(RenderWindow* window, Texture* pTexture);
	~Player();
	
};

