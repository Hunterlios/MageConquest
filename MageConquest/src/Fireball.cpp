#include "Fireball.h"

void Fireball::Update(float deltaTime, Vector2f aimDirNorm)
{
	this->moveBall(aimDirNorm, deltaTime);
}

void Fireball::Render()
{
	this->window->draw(shape);
}

void Fireball::moveBall(Vector2f aimDirNorm, float deltaTime)
{
	this->shape.move(Vector2f(aimDirNorm.x*deltaTime*10.f, aimDirNorm.y*deltaTime*10.f));
}

CircleShape Fireball::getShape()
{
	return this->shape;
}

Fireball::Fireball(RenderWindow* window, ResourcesManager& resManager, Vector2f playerPosition)
{
	this->window = window;
	this->shape.setRadius(6.f);
	this->shape.setPosition(playerPosition);
	this->shape.setTexture(&resManager.GetTexture("fireball"));
}

Fireball::~Fireball()
{

}

Vector2f Fireball::getPosition(Vector2f aimDirNorm, float deltaTime)
{
	return Vector2f(aimDirNorm.x * deltaTime * 10.f, aimDirNorm.y * deltaTime * 10.f);
}
