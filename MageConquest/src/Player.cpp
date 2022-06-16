#include "Player.h"

RectangleShape Player::getShape()
{
	return shape;
}

Vector2f Player::getCenter()
{
	return Vector2f(shape.getPosition().x + (shape.getSize().x/2), shape.getPosition().y + (shape.getSize().y / 2));
}


void Player::Update(float deltaTime, ResourcesManager& resManager)
{
	
	this->updateFireballWindowCollision();
	this->elapseShootTimer = cooldown.getElapsedTime();

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->shape.move(Vector2f(-150.f * deltaTime, 0.f));
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->shape.move(Vector2f(150.f * deltaTime, 0.f));
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->shape.move(Vector2f(0.f, -150.f * deltaTime));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->shape.move(Vector2f(0.f, 150.f * deltaTime));
	}

	if (Mouse::isButtonPressed(Mouse::Left) && elapseShootTimer.asSeconds()>=0.5f)
	{
		this->velocity = aimDirNorm * deltaTime * 300.f;
		this->shots.push_back(new Fireball(window, resManager, getCenter(), velocity));
		this->cooldown.restart();
	}
	
	for (int i = 0; i < shots.size(); i++)
	{
		shots[i]->Update();
	}
	
	
	this->updateWindowBoundsCollision();

}

void Player::Render()
{

	for (int i = 0; i < shots.size(); i++)
	{
		shots[i]->Render();
	}


	window->draw(shape);
}

void Player::updateWindowBoundsCollision()
{
	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		this->shape.setPosition(0.f, shape.getGlobalBounds().top);
	}
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= window->getSize().x)
	{
		this->shape.setPosition(window->getSize().x - shape.getGlobalBounds().width, shape.getGlobalBounds().top);
	}
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	}
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= window->getSize().y)
	{
		this->shape.setPosition(shape.getGlobalBounds().left, window->getSize().y - shape.getGlobalBounds().height);
	}
	
}

void Player::updateFireballWindowCollision()
{
	for (size_t i = 0; i < shots.size(); i++)
	{
		if (shots[i]->getShape().getPosition().x < 0 || shots[i]->getShape().getPosition().x > window->getSize().x || shots[i]->getShape().getPosition().y < 0 || shots[i]->getShape().getPosition().y > window->getSize().y)
		{
			shots.erase(shots.begin() + i);
		}
	}
	
}

void Player::getMousePos()
{
	this->pixelPos = Mouse::getPosition(*window);
	this->worldPos = this->window->mapPixelToCoords(pixelPos);
	this->mousePosition = worldPos;
	this->aimDir = mousePosition - getCenter();
	this->aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	this->aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
}

Player::Player(RenderWindow* window, ResourcesManager& resManager)
{
	this->window = window;
	this->shape.setTexture(&resManager.GetTexture("playerTexture"));
	this->shape.setSize(Vector2f(15.f, 25.f));
	this->shape.setPosition(Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f));

}

Player::~Player()
{
	for (int i = 0; i < shots.size(); i++)
	{
		delete this->shots[i];
	}

	this->shots.clear();
}
