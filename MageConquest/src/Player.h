#pragma once
#include"pch.h"
#include"TextureLoader.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	TextureLoader* pTexture;
	Texture pTex;
	
public:
	RectangleShape getShape();
	void Update(float deltaTime);
	void Render();
	Player(RenderWindow* window);
	~Player();
};

