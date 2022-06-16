#include "Fireball.h"

void Fireball::Update()
{
	this->moveBall();
}

void Fireball::Render()
{
	this->window->draw(shape);
}

void Fireball::moveBall()
{
	this->shape.move(this->velocity);
}

CircleShape Fireball::getShape()
{
	return this->shape;
}

Fireball::Fireball(RenderWindow* window, ResourcesManager& resManager, Vector2f playerPosition, Vector2f velocity)
{
	this->window = window;
	this->velocity = velocity;
	this->shape.setRadius(6.f);
	this->shape.setPosition(playerPosition);
	this->shape.setTexture(&resManager.GetTexture("fireball"));
}

Fireball::~Fireball()
{
}

