#pragma once
#include"pch.h"
#include"ResourcesManager.h"
class Enemy
{
protected:
	RenderWindow* window;
	RectangleShape shape;
	Vector2f dir;
	Vector2f dirNorm;
	float x, y;
	int enemyHp;

public:
	Vector2f velocity;
	Enemy();
	Enemy(RenderWindow* window, ResourcesManager& resManager);
	virtual ~Enemy();
	void collision(vector<Enemy*> enemies);
	int getHp();
	void changeHp(int value);
	virtual void setPos(Vector2f pos) = 0;
	virtual Vector2f getVelocity() = 0;
	virtual void Update(float deltaTime, Vector2f playerCenter) = 0;
	virtual void Render() = 0;
	virtual RectangleShape getShape() = 0;
};

