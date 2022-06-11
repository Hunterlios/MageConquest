#include "EnemySystem.h"

EnemySystem::EnemySystem(RenderWindow* window)
{
	this->window = window;
}

EnemySystem::~EnemySystem()
{
	this->activeEnemies.clear();
}

void EnemySystem::createEnemy(EnemyTypes type, ResourcesManager& resManager)
{
	switch (type)
	{
	case EnemyTypes::RAT:
		this->activeEnemies.push_back(new Rat(window, resManager));
		break;
	default:
		cout << "ERROR TYPE OF ENEMY DOES NOT EXIST\n";
		break;
	}
}

void EnemySystem::Update(float deltaTime)
{
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		activeEnemies[i]->Update(deltaTime);
	}
	
}

void EnemySystem::Render()
{	
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		activeEnemies[i]->Render();
	}
	
}
