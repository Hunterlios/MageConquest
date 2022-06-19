#include "PlayerGUI.h"

void PlayerGUI::Update()
{
	this->hp = this->player->playerHp;
	this->score = player->score;
	this->scoreText.setString(to_string(score));
	this->hpBar.setSize(Vector2f(hp, 10.f));
	this->hpBarOutline.setPosition(player->getCenter().x - 300.f, player->getCenter().y - 170.f);
	this->hpBar.setPosition(player->getCenter().x - 300.f, player->getCenter().y - 170.f);
	this->scoreText.setPosition(player->getCenter().x - 300.f, player->getCenter().y - 155.f);
}

void PlayerGUI::Render()
{
	this->window->draw(hpBar);
	this->window->draw(hpBarOutline);
	this->window->draw(scoreText);
}

PlayerGUI::PlayerGUI(RenderWindow* window, Player* player, Font& font)
{
	this->window = window;
	this->player = player;
	this->hp = this->player->playerHp;
	this->hpBar.setSize(Vector2f(hp, 10.f));
	this->hpBarOutline.setSize(Vector2f(hp, 10.f));
	this->hpBar.setFillColor(Color::Red);
	this->hpBarOutline.setFillColor(Color::Transparent);
	this->hpBarOutline.setOutlineColor(Color::White);
	this->hpBarOutline.setOutlineThickness(1.f);
	this->scoreText.setFont(font);
	this->scoreText.setFillColor(Color::White);
	this->scoreText.setCharacterSize(8.f);
}

PlayerGUI::~PlayerGUI()
{
}
