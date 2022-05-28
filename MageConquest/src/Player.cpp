#include "Player.h"

RectangleShape Player::getShape()
{
	return shape;
}


void Player::Update(float deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->shape.move(Vector2f(-200.f * deltaTime, 0.f));
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->shape.move(Vector2f(200.f * deltaTime, 0.f));
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->shape.move(Vector2f(0.f, -200.f * deltaTime));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->shape.move(Vector2f(0.f, 200.f * deltaTime));
	}
}

void Player::Render()
{
	window->draw(shape);
}

Player::Player(RenderWindow* window)
{
	this->window = window;
	this->shape.setSize(Vector2f(15.f, 25.f));
	this->shape.setPosition(Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f));
}

Player::~Player()
{
}
