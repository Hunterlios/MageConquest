#pragma once
#include"Rat.h"

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
	void Update(float deltaTime);
	void Render();
};
 
