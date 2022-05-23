#include "Camera.h"

void Camera::Update()
{
	this->view.setCenter(this->player->getShape().getPosition());
	if (view.getCenter().x < view.getSize().x / 2.f)
	{
		view.setCenter(Vector2f(view.getSize().x / 2.f, view.getCenter().y));
	}
	if (view.getCenter().x > window->getSize().x - view.getSize().x / 2.f)
	{
		view.setCenter(Vector2f(window->getSize().x - view.getSize().x / 2.f, view.getCenter().y));
	}
	if (view.getCenter().y > window->getSize().y - view.getSize().y / 2.f)
	{
		view.setCenter(Vector2f(view.getCenter().x, window->getSize().y - view.getSize().y / 2.f));
	}
	if (view.getCenter().y < view.getSize().y / 2.f)
	{
		view.setCenter(Vector2f(view.getCenter().x, view.getSize().y / 2.f));
	}
}

void Camera::Render()
{
	this->window->setView(view);
}

Camera::Camera(RenderWindow* window, Player* player)
{
	this->player = player;
    this->window = window;
    view.setSize(Vector2f(680.f, 360.f));
}



Camera::~Camera()
{
}
