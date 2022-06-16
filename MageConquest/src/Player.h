#pragma once
#include"ResourcesManager.h"
#include"Fireball.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	Vector2f position;
	Clock cooldown;
	Time elapseShootTimer;
	Vector2f mousePosition;
	Vector2f aimDir;
	Vector2f aimDirNorm;
	Vector2f velocity;
	Vector2i pixelPos;
	Vector2f worldPos;
	
public:
	vector<Fireball*> shots;
	RectangleShape getShape();
	Vector2f getCenter();
	void Update(float deltaTime, ResourcesManager& resManager);
	void Render();
	void updateWindowBoundsCollision();
	void updateFireballWindowCollision();
	void getMousePos();
	Player(RenderWindow* window, ResourcesManager& resManager);
	~Player();
};
