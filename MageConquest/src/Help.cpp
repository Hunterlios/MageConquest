#include "Help.h"
Help::Help(RenderWindow* window, Font& font, ResourcesManager& resManager)
{
	this->window = window;
	this->background.setTexture(resManager.GetTexture("menuBackground"));
	for (int i = 0; i < 2; i++)
	{
		help[i].setFont(font);
		help[i].setFillColor(Color::White);
		help[i].setPosition(Vector2f(window->getSize().x / 2.f, window->getSize().y / 4 * (i + 1)));
	}
	help[0].setString("Use WSDA keys to move and LEFT \n mouse button to shoot enemies");
	help[1].setString("BACK");
}

Help::~Help()
{
}

int Help::getPressedItem()
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		auto mousePosition = Mouse::getPosition(*window);
		auto mousePositionInWindow = window->mapPixelToCoords(mousePosition);

		if (this->help[0].getGlobalBounds().contains(mousePositionInWindow))
		{
			return 1;
		}
		else if (this->help[1].getGlobalBounds().contains(mousePositionInWindow))
		{
			return 2;
		}
	}
}

void Help::Update()
{
}

void Help::Render()
{
	window->clear();
	window->draw(background);
	for (int i = 0; i < 2; i++)
	{
		window->draw(help[i]);
	}
	window->display();
}