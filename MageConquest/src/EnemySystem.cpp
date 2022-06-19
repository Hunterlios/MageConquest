#include "EnemySystem.h"

EnemySystem::EnemySystem(RenderWindow* window)
{
	this->window = window;
	this->damage = 15;
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
	Enemy* enemy;
	switch (type)
	{
	case EnemyTypes::RAT:
		enemy = new Rat(window, resManager);
		this->activeEnemies.push_back(enemy);
		break;

	case EnemyTypes::GOBLIN:
		enemy = new Goblin(window, resManager);
		this->activeEnemies.push_back(enemy);
		break;

	case EnemyTypes::SKELETON:
		enemy = new Skeleton(window, resManager);
		this->activeEnemies.push_back(enemy);
		break;

	case EnemyTypes::VAMPIRE:
		enemy = new Vampire(window, resManager);
		this->activeEnemies.push_back(enemy);
		break;

	default:
		cout << "ERROR TYPE OF ENEMY DOES NOT EXIST\n";
		break;
	}
}

void EnemySystem::intersection(vector<Fireball*>& shots, int& score)
{
	int enemyHealth{};
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		enemyHealth = activeEnemies[i]->getHp();
		for (int j = 0; j < shots.size(); j++)
		{
			if (activeEnemies[i]->getShape().getGlobalBounds().intersects(shots[j]->getShape().getGlobalBounds()) && dynamic_cast<Rat*>(activeEnemies[i]) != nullptr)
			{
				if (enemyHealth - damage > 0)
				{
					activeEnemies[i]->changeHp(damage);
					shots.erase(shots.begin() + j);
				}
				else
				{
					activeEnemies.erase(activeEnemies.begin() + i);
					shots.erase(shots.begin() + j);
					score = score + 10;
				}
			}
			else if (activeEnemies[i]->getShape().getGlobalBounds().intersects(shots[j]->getShape().getGlobalBounds()) && dynamic_cast<Goblin*>(activeEnemies[i]) != nullptr)
			{
				if (enemyHealth - damage > 0)
				{
					activeEnemies[i]->changeHp(damage);
					shots.erase(shots.begin() + j);
				}
				else
				{
					activeEnemies.erase(activeEnemies.begin() + i);
					shots.erase(shots.begin() + j);
					score = score + 20;
				}
			}
			else if (activeEnemies[i]->getShape().getGlobalBounds().intersects(shots[j]->getShape().getGlobalBounds()) && dynamic_cast<Skeleton*>(activeEnemies[i]) != nullptr)
			{
				if (enemyHealth - damage > 0)
				{
					activeEnemies[i]->changeHp(damage);
					shots.erase(shots.begin() + j);
				}
				else
				{
					activeEnemies.erase(activeEnemies.begin() + i);
					shots.erase(shots.begin() + j);
					score = score + 30;
				}
			}
			else if (activeEnemies[i]->getShape().getGlobalBounds().intersects(shots[j]->getShape().getGlobalBounds()) && dynamic_cast<Vampire*>(activeEnemies[i]) != nullptr)
			{
				if (enemyHealth - damage > 0)
				{
					activeEnemies[i]->changeHp(damage);
					shots.erase(shots.begin() + j);
				}
				else
				{
					activeEnemies.erase(activeEnemies.begin() + i);
					shots.erase(shots.begin() + j);
					score = score + 50;
				}
			}
		}
	}
}

void EnemySystem::Update(float deltaTime, vector<Fireball*>& shots, Vector2f playerCenter, int& score)
{
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		activeEnemies[i]->Update(deltaTime, playerCenter);
		activeEnemies[i]->collision(activeEnemies);
	}
	this->intersection(shots, score);
}

void EnemySystem::Render()
{	
	for (int i = 0; i < activeEnemies.size(); i++)
	{
		activeEnemies[i]->Render();
	}
}
