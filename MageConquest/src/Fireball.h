#pragma once
#include"pch.h"
#include"ResourcesManager.h"


class Fireball
{
private:
	RenderWindow* window;
	CircleShape shape;
	Vector2f position;
	Vector2f velocity;


public:
	void Update();
	void Render();
	void moveBall();
	CircleShape getShape();
	Fireball(RenderWindow* window, ResourcesManager& resManager, Vector2f playerPosition, Vector2f velocity);
	~Fireball();

};

