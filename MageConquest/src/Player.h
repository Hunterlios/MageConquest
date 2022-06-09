#pragma once
#include"ResourcesManager.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	Vector2f position;

	
public:
	RectangleShape getShape();
	Vector2f getPosition();
	void Update(float deltaTime);
	void Render();
	void updateWindowBoundsCollision(RenderWindow* window);
	Player(RenderWindow* window, ResourcesManager& resManager);
	~Player();
};

