#pragma once
#include"pch.h"
#include"ResourcesManager.h"
#include"Player.h"
class Enemy
{
protected:
	RenderWindow* window;
	RectangleShape shape;
	Vector2f dir;
	Vector2f dirNorm;
	float x, y;

public:
	Vector2f velocity;
	Enemy();
	Enemy(RenderWindow* window, ResourcesManager& resManager);
	~Enemy();
	void collision(Enemy* enemy, vector<Enemy*> enemies);
	virtual void setPos(Vector2f pos) = 0;
	virtual Vector2f getVelocity() = 0;
	virtual void Update(float deltaTime, Vector2f playerCenter) = 0;
	virtual void Render() = 0;
	virtual RectangleShape getShape() = 0;
};

