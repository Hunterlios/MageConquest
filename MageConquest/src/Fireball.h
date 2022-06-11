#pragma once
#include "pch.h"
#include"ResourcesManager.h"


class Fireball
{
private:
	RenderWindow* window;
	CircleShape shape;
	Vector2f position;


public:
	void Update(float deltaTime, Vector2f aimDirNorm);
	void Render();
	void moveBall(Vector2f aimDirNorm, float deltaTime);
	CircleShape getShape();
	Fireball(RenderWindow* window, ResourcesManager& resManager, Vector2f playerPosition);
	~Fireball();
	Vector2f getPosition(Vector2f aimDirNorm, float deltaTime);

};

