#include "Game.h"

Game::Game()
{
	this->window = new RenderWindow(VideoMode(1920, 1080), "MageConquest", Style::Close | Style::Titlebar);
	this->window->setKeyRepeatEnabled(true);
	this->window->setFramerateLimit(60);
	this->event = Event();
	this->pTexture = new Texture;
	this->pTexture->loadFromFile("Mage.png");
	this->player = new Player(this->window, this->pTexture);
	this->camera = new Camera(this->window, this->player);
}

Game::~Game()
{
	delete this->window;
	delete this->camera;
	delete this->player;
	delete this->pTexture;
}

void Game::Run()
{
	while (this->window->isOpen())
	{
		UpdateEvents();
		this->Update();
		this->Render();
	}
}

void Game::UpdateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
		{
			this->window->close();
		}
	}
	
}

void Game::Update()
{
	this->deltaTime = clock.restart();
	this->player->Update(deltaTime.asSeconds());
	this->camera->Update();
}

void Game::Render()
{
	this->window->clear();
	this->camera->Render();
	this->player->Render();
	this->window->display();
}
