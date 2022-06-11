#pragma once
#include"pch.h"
#include"ResourcesManager.h"
#include"Player.h"
class Enemy
{
private:
	RenderWindow* window;

public:
	Enemy();
	Enemy(RenderWindow* window);
	~Enemy();
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
};

