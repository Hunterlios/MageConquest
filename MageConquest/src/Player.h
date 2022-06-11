#pragma once
#include"ResourcesManager.h"
#include "Fireball.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	Vector2f position;
	vector<Fireball*> shots;
	Clock cooldown;
	Time elapseShootTimer;
	Vector2f mousePosition;
	Vector2f aimDir;
	Vector2f aimDirNorm;
	
public:
	RectangleShape getShape();
	Vector2f getPosition();
	void Update(float deltaTime, ResourcesManager& resManager);
	void Render();
	void updateWindowBoundsCollision(RenderWindow* window);
	Player(RenderWindow* window, ResourcesManager& resManager);
	~Player();
};

