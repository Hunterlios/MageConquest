#include "Vampire.h"

Vampire::Vampire(RenderWindow* window, ResourcesManager& resManager)
{
	this->window = window;
	this->enemyHp = 60;
	this->shape.setSize(Vector2f(15.f, 25.f));
	this->shape.setPosition(generatePos());
	this->shape.setTexture(&resManager.GetTexture("vampireTexture"));
}

Vampire::~Vampire()
{
}

Vector2f Vampire::generatePos()
{
	x = rand() % window->getSize().x - shape.getSize().x;
	y = rand() % window->getSize().y - shape.getSize().y;
	return Vector2f(x, y);
}

void Vampire::setPos(Vector2f pos)
{
	shape.setPosition(pos);
}

Vector2f Vampire::getVelocity()
{
	return velocity;
}

void Vampire::Update(float deltaTime, Vector2f playerCenter)
{
	dir = playerCenter - Vector2f(shape.getPosition().x + (shape.getSize().x / 2), shape.getPosition().y + (shape.getSize().y / 2));
	dirNorm.x = dir.x / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	dirNorm.y = dir.y / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	velocity = dirNorm * deltaTime * 110.f;
	this->shape.move(velocity);
}

void Vampire::Render()
{
	this->window->draw(shape);
}

RectangleShape Vampire::getShape()
{
	return shape;
}
