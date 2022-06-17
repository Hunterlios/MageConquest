#pragma once
#include"Rat.h"
#include"Player.h"

enum EnemyTypes
{
	RAT = 0
};

class EnemySystem
{
private:
	RenderWindow* window;
	vector<Enemy*> activeEnemies;

public:
	EnemySystem(RenderWindow* window);
	~EnemySystem();
	void createEnemy(EnemyTypes type, ResourcesManager& resManager);
	void intersection(vector<Fireball*>& shots);
	void Update(float deltaTime, vector<Fireball*>& shots, Vector2f playerCenter);
	void Render();
};
 
