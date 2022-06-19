#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(RenderWindow* window, ResourcesManager& resManager)
{
	this->window = window;
}

Enemy::~Enemy()
{
}

void Enemy::collision(vector<Enemy*> enemies)
{
	for (auto& enemy2 : enemies)
	{
		if (this == enemy2)
		{
			continue;
		}
		FloatRect enemy1Bounds = shape.getGlobalBounds();
		FloatRect enemy2Bounds = enemy2->getShape().getGlobalBounds();
		FloatRect nextPos = enemy1Bounds;
		nextPos.left += this->velocity.x;
		nextPos.top += this->velocity.y;


		if (enemy2Bounds.intersects(nextPos))
		{
			if (enemy1Bounds.top < enemy2Bounds.top
				&& enemy1Bounds.top + enemy1Bounds.height < enemy2Bounds.top + enemy2Bounds.height
				&& enemy1Bounds.left < enemy2Bounds.left + enemy2Bounds.width
				&& enemy1Bounds.left + enemy1Bounds.width > enemy2Bounds.left)
			{
				this->velocity.y = 0.f;
				this->setPos(Vector2f(enemy1Bounds.left, enemy2Bounds.top - enemy1Bounds.height));
			}
			else if (enemy1Bounds.top > enemy2Bounds.top
				&& enemy1Bounds.top + enemy1Bounds.height > enemy2Bounds.top + enemy2Bounds.height
				&& enemy1Bounds.left < enemy2Bounds.left + enemy2Bounds.width
				&& enemy1Bounds.left + enemy1Bounds.width > enemy2Bounds.left)
			{
				this->velocity.y = 0.f;
				this->setPos(Vector2f(enemy1Bounds.left, enemy2Bounds.top + enemy2Bounds.height));
			}
			if (enemy1Bounds.left < enemy2Bounds.left
				&& enemy1Bounds.left + enemy1Bounds.width < enemy2Bounds.left + enemy2Bounds.width
				&& enemy1Bounds.top < enemy2Bounds.top + enemy2Bounds.height
				&& enemy1Bounds.top + enemy1Bounds.height > enemy2Bounds.top)
			{
				this->velocity.x = 0.f;
				this->setPos(Vector2f(enemy2Bounds.left - enemy1Bounds.width, enemy1Bounds.top));
			}
			else if (enemy1Bounds.left > enemy2Bounds.left
				&& enemy1Bounds.left + enemy1Bounds.width > enemy2Bounds.left + enemy2Bounds.width
				&& enemy1Bounds.top < enemy2Bounds.top + enemy2Bounds.height
				&& enemy1Bounds.top + enemy1Bounds.height > enemy2Bounds.top)
			{
				this->velocity.x = 0.f;
				this->setPos(Vector2f(enemy2Bounds.left + enemy2Bounds.width, enemy1Bounds.top));
			}
		}
	}
}

int Enemy::getHp()
{
	return enemyHp;
}

void Enemy::changeHp(int value)
{
	enemyHp -= value;
}



