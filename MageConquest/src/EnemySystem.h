#pragma once
#include"Enemies.h"
#include"Player.h"

enum EnemyTypes
{
	RAT = 0,
	GOBLIN = 1,
	SKELETON = 2,
	VAMPIRE = 3
};

class EnemySystem
{
private:
	RenderWindow* window;
	int damage;
	
public:
	vector<Enemy*> activeEnemies;
	EnemySystem(RenderWindow* window);
	~EnemySystem();
	void createEnemy(EnemyTypes type, ResourcesManager& resManager);
	void intersection(vector<Fireball*>& shots, int& score);
	void Update(float deltaTime, vector<Fireball*>& shots, Vector2f playerCenter, int& score);
	void Render();
};
 
