#pragma once
#include"pch.h"
#include"TextureLoader.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	TextureLoader tex;
	
public:
	RectangleShape getShape();
	void Update(float deltaTime);
	void Render();
	void updateWindowBoundsCollision(RenderWindow* window);
	Player(RenderWindow* window);
	~Player();
};

