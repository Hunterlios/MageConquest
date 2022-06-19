#include "Camera.h"

void Camera::Update()
{
	this->playerGUI->Update();
	this->view.setCenter(this->player->getShape().getPosition());
	if (view.getCenter().x < view.getSize().x / 2.f)
	{
		view.setCenter(Vector2f(view.getSize().x / 2.f, view.getCenter().y));
		playerGUI->hpBar.setPosition(Vector2f(27.5f, view.getCenter().y - 157.5f));
		playerGUI->hpBarOutline.setPosition(Vector2f(27.5f, view.getCenter().y - 157.5f));
		playerGUI->scoreText.setPosition(Vector2f(27.5f, view.getCenter().y - 142.5f));
	}
	if (view.getCenter().x > window->getSize().x - view.getSize().x / 2.f)
	{
		view.setCenter(Vector2f(window->getSize().x - view.getSize().x / 2.f, view.getCenter().y));
		playerGUI->hpBar.setPosition(Vector2f(window->getSize().x - view.getSize().x + 27.5f, view.getCenter().y - 157.5f));
		playerGUI->hpBarOutline.setPosition(Vector2f(window->getSize().x - view.getSize().x + 27.5f, view.getCenter().y - 157.5f));
		playerGUI->scoreText.setPosition(Vector2f(window->getSize().x - view.getSize().x + 27.5f, view.getCenter().y - 142.5f));
	}
	if (view.getCenter().y > window->getSize().y - view.getSize().y / 2.f)
	{
		view.setCenter(Vector2f(view.getCenter().x, window->getSize().y - view.getSize().y / 2.f));
		playerGUI->hpBar.setPosition(Vector2f(view.getCenter().x - 292.5f, window->getSize().y - view.getSize().y + 22.5f));
		playerGUI->hpBarOutline.setPosition(Vector2f(view.getCenter().x - 292.5f, window->getSize().y - view.getSize().y + 22.5f));
		playerGUI->scoreText.setPosition(Vector2f(view.getCenter().x - 292.5f, window->getSize().y - view.getSize().y + 37.5f));
	}
	if (view.getCenter().y < view.getSize().y / 2.f)
	{
		view.setCenter(Vector2f(view.getCenter().x, view.getSize().y / 2.f));
		playerGUI->hpBar.setPosition(Vector2f(view.getCenter().x - 292.5f, 22.5f));
		playerGUI->hpBarOutline.setPosition(Vector2f(view.getCenter().x - 292.5f, 22.5f));
		playerGUI->scoreText.setPosition(Vector2f(view.getCenter().x - 292.5f, 37.5f));
	}
}

void Camera::Render()
{
	this->window->setView(view);
	this->playerGUI->Render();
}

Camera::Camera(RenderWindow* window, Player* player, PlayerGUI* playerGUI)
{
	this->player = player;
    this->window = window;
	this->playerGUI = playerGUI;
    view.setSize(Vector2f(640.f, 360.f));
}



Camera::~Camera()
{
}
