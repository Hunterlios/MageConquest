#pragma once
#include"pch.h"
#include"ResourcesManager.h"
#include"Player.h"
class Enemy
{
private:
	RenderWindow* window;
	RectangleShape shape;
	Vector2f dir;
	Vector2f dirNorm;

public:
	Enemy();
	Enemy(RenderWindow* window, ResourcesManager& resManager);
	~Enemy();
	virtual void Update(float deltaTime, Vector2f playerCenter) = 0;
	virtual void Render() = 0;
	virtual RectangleShape getShape() = 0;
};

