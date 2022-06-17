#include "Rat.h"

Rat::Rat(RenderWindow* window, ResourcesManager& resManager)
{
	this->window = window;
	this->shape.setSize(Vector2f(15.f, 10.f));
	this->shape.setPosition(generatePos());
	this->shape.setTexture(&resManager.GetTexture("ratTexture"));
}

Rat::~Rat()
{
}

Vector2f Rat::generatePos()
{
	x = rand() % int(window->getSize().x - shape.getSize().x);
	y = rand() % int(window->getSize().y - shape.getSize().y);
	return Vector2f(x, y);
}

void Rat::Render()
{
	this->window->draw(shape);
}

RectangleShape Rat::getShape()
{
	return shape;
}

void Rat::Update(float deltaTime, Vector2f playerCenter)
{
	dir = playerCenter - Vector2f(shape.getPosition().x + (shape.getSize().x / 2), shape.getPosition().y + (shape.getSize().y / 2));
	dirNorm.x = dir.x / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	dirNorm.y = dir.y / sqrt(pow(dir.x, 2) + pow(dir.y, 2));
	this->shape.move(Vector2f(dirNorm * deltaTime * 100.f));
}


