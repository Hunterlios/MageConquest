#include "Rat.h"

Rat::Rat(RenderWindow* window, ResourcesManager& resManager)
{
	this->window = window;
	this->shape.setSize(Vector2f(15.f, 10.f));
	this->shape.setPosition(Vector2f(800.f, 600.f));
	this->shape.setTexture(&resManager.GetTexture("ratTexture"));
}

Rat::~Rat()
{
}

void Rat::Render()
{
	this->window->draw(shape);
}

void Rat::Update(float deltaTime)
{
	this->shape.move(Vector2f(10.f * deltaTime, 3.f * deltaTime));
}


