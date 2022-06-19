#include "Skeleton.h"

Skeleton::Skeleton(RenderWindow* window, ResourcesManager& resManager)
{
	this->window = window;
	this->enemyHp = 45;
	this->shape.setSize(Vector2f(15.f, 25.f));
	this->shape.setPosition(generatePos());
	this->shape.setTexture(&resManager.GetTexture("skeletonTexture"));
}

Skeleton::~Skeleton()
{
}

Vector2f Skeleton::generatePos()
{
	x = rand() % window->getSize().x - shape.getSize().x;
	y = rand() % window->getSize().y - shape.getSize().y;
	return Vector2f(x, y);
}

void Skeleton::setPos(Vector2f pos)
{
	shape.setPosition(pos);
}

Vector2f Skeleton::getVelocity()
{
	return velocity;
}

void Skeleton::Update(float deltaTime, Vector2f playerCenter)
{
	dir = playerCenter - Vector2f(shape.getPosition().x + (shape.getSize().x / 2), shape.getPosition().y + (shape.getSize().y / 2));
	dirNorm.x = dir.x / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	dirNorm.y = dir.y / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	velocity = dirNorm * deltaTime * 115.f;
	this->shape.move(velocity);
}

void Skeleton::Render()
{
	this->window->draw(shape);
}

RectangleShape Skeleton::getShape()
{
	return shape;
}
