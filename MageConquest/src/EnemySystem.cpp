#include "EnemySystem.h"

EnemySystem::EnemySystem(RenderWindow* window)
{
	this->window = window;
}

EnemySystem::~EnemySystem()
{
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		delete this->activeEnemies[i];
	}

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

void EnemySystem::intersection(vector<Fireball*>& shots)
{
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		for (int j = 0; j < shots.size(); j++)
		{
			if (activeEnemies[i]->getShape().getGlobalBounds().intersects(shots[j]->getShape().getGlobalBounds()))
			{
				activeEnemies.erase(activeEnemies.begin() + i);
				shots.erase(shots.begin() + j);
			}
		}
	}
}

void EnemySystem::Update(float deltaTime, vector<Fireball*>& shots)
{
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		activeEnemies[i]->Update(deltaTime);
	}
	this->intersection(shots);
}

void EnemySystem::Render()
{	
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		activeEnemies[i]->Render();
	}
	
}
