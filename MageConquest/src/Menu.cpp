#include "Menu.h"

Menu::Menu(RenderWindow* window, Font& font, ResourcesManager& resManager)
{
	this->window = window;
	this->background.setTexture(resManager.GetTexture("menuBackground"));
	for (int i = 0; i < 3; i++)
	{
		menu[i].setFont(font);
		menu[i].setFillColor(Color::White);
		menu[i].setPosition(Vector2f(window->getSize().x / 2.f, window->getSize().y / 4 * (i + 1)));
	}
	menu[0].setString("PLAY");
	menu[1].setString("HOW TO PLAY");
	menu[2].setString("EXIT");
}

Menu::~Menu()
{
}

int Menu::getPressedItem()
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		auto mousePosition = Mouse::getPosition(*window);
		auto mousePositionInWindow = window->mapPixelToCoords(mousePosition);

		if (this->menu[0].getGlobalBounds().contains(mousePositionInWindow))
		{
			return 1;
		}
		else if (this->menu[1].getGlobalBounds().contains(mousePositionInWindow))
		{
			return 2;
		}
		else if (this->menu[2].getGlobalBounds().contains(mousePositionInWindow))
		{
			return 3;
		}
	}
}

void Menu::Update(float& deltaTime)
{
}

void Menu::Render()
{
	window->draw(background);
	for (int i = 0; i < 3; i++)
	{
		window->draw(menu[i]);
	}
}
