#include "GameOver.h"

GameOver::GameOver(RenderWindow* window, Font& font, ResourcesManager& resManager, int score)
{
	this->highscoreRead.open("highscore.txt");
	this->highscoreRead >> highestPoints;
	this->highscoreRead.close();
	if (score > highestPoints)
	{
		highestPoints = score;
		highscoreWrite.open("highscore.txt");
		highscoreWrite << score << "\n";
		highscoreWrite.close();
	}
	this->window = window;
	this->background.setTexture(resManager.GetTexture("menuBackground"));
	for (int i = 0; i < 2; i++)
	{
		text[i].setFont(font);
		text[i].setFillColor(Color::White);
		text[i].setPosition(Vector2f(window->getSize().x / 2.f, window->getSize().y / 4 * (i + 1)));
	}
	text[0].setString("GAME OVER\n\nYOUR SCORE: " + to_string(score) + "\nHIGHSCORE: " + to_string(highestPoints));
	text[1].setString("EXIT");
}

GameOver::~GameOver()
{
}

int GameOver::getPressedItem()
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		auto mousePosition = Mouse::getPosition(*window);
		auto mousePositionInWindow = window->mapPixelToCoords(mousePosition);

		if (this->text[0].getGlobalBounds().contains(mousePositionInWindow))
		{
			return 1;
		}
		else if (this->text[1].getGlobalBounds().contains(mousePositionInWindow))
		{
			return 2;
		}
	}
}

void GameOver::Update(float& deltaTime)
{
}

void GameOver::Render()
{
	window->setView(window->getDefaultView());
	window->draw(background);
	for (int i = 0; i < 2; i++)
	{
		window->draw(text[i]);
	}
}
