#pragma once
#include"Fireball.h"
#include"Enemy.h"
#include"Enemies.h"

class Player
{
private:
	RenderWindow* window;
	RectangleShape shape;
	Vector2f position;
	Clock cooldown, damageCooldown;
	Time elapseShootTimer, elapseDamageTimer;
	Vector2f mousePosition;
	Vector2f aimDir;
	Vector2f aimDirNorm;
	Vector2f velocity;
	Vector2i pixelPos;
	Vector2f worldPos;
	
	
public:
	int score;
	int playerHp;
	vector<Fireball*> shots;
	RectangleShape getShape();
	Vector2f getCenter();
	void Update(float deltaTime, ResourcesManager& resManager, vector<Enemy*> enemies);
	void Render();
	void updateWindowBoundsCollision();
	void updateFireballWindowCollision();
	void updateEnemyCollision(vector<Enemy*> enemies);
	void getMousePos();
	Player(RenderWindow* window, ResourcesManager& resManager);
	~Player();
};
