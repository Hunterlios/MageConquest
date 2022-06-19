#include "Goblin.h"

Goblin::Goblin(RenderWindow* window, ResourcesManager& resManager)
{
	this->window = window;
	this->enemyHp = 20;
	this->shape.setSize(Vector2f(10.f, 15.f));
	this->shape.setPosition(generatePos());
	this->shape.setTexture(&resManager.GetTexture("goblinTexture"));
}

Goblin::~Goblin()
{
}

Vector2f Goblin::generatePos()
{
	x = rand() % window->getSize().x - shape.getSize().x;
	y = rand() % window->getSize().y - shape.getSize().y;
	return Vector2f(x, y);
}

void Goblin::setPos(Vector2f pos)
{
	shape.setPosition(pos);
}

Vector2f Goblin::getVelocity()
{
	return velocity;
}

void Goblin::Update(float deltaTime, Vector2f playerCenter)
{
	dir = playerCenter - Vector2f(shape.getPosition().x + (shape.getSize().x / 2), shape.getPosition().y + (shape.getSize().y / 2));
	dirNorm.x = dir.x / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	dirNorm.y = dir.y / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	velocity = dirNorm * deltaTime * 125.f;
	this->shape.move(velocity);
}

void Goblin::Render()
{
	this->window->draw(shape);
}

RectangleShape Goblin::getShape()
{
	return shape;
}
