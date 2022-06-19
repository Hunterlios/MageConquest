#include "Game.h"

Game::Game(RenderWindow* window, ResourcesManager& resManager, Font& font)
{
	this->window = window;
	this->resManager = resManager;
	this->font = font;
	this->event = Event();
	this->enemySystem = new EnemySystem(this->window);
	for (int i = 0; i < 8; i++)
	{
		this->enemySystem->createEnemy(RAT, this->resManager);
		this->enemySystem->createEnemy(GOBLIN, this->resManager);
		this->enemySystem->createEnemy(SKELETON, this->resManager);
		this->enemySystem->createEnemy(VAMPIRE, this->resManager);
	}
	this->background.setTexture(this->resManager.GetTexture("background"));
	this->player = new Player(this->window, this->resManager);
	this->playerGUI = new PlayerGUI(this->window, this->player, this->font);
	this->camera = new Camera(this->window, this->player, this->playerGUI);
}

Game::~Game()
{
	delete this->camera;
	delete this->player;
	delete this->playerGUI;
	delete this->enemySystem;
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

		if (this->event.type == Event::KeyPressed)
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				this->window->close();
			}
			
		}
	}
	
}

void Game::spawnEnemy()
{
	if (enemySystem->activeEnemies.size() <= 8)
	{
		for (int i = 0; i < 8; i++)
		{
			this->enemySystem->createEnemy(RAT, this->resManager);
			this->enemySystem->createEnemy(GOBLIN, this->resManager);
			this->enemySystem->createEnemy(SKELETON, this->resManager);
			this->enemySystem->createEnemy(VAMPIRE, this->resManager);
		}
	}
	
}

void Game::Update()
{
	this->deltaTime = clock.restart();
	this->player->Update(deltaTime.asSeconds(), this->resManager, this->enemySystem->activeEnemies);
	this->camera->Update();
	this->enemySystem->Update(deltaTime.asSeconds(), this->player->shots, player->getCenter(), player->score);
	this->spawnEnemy();
}

void Game::Render()
{
	this->window->clear();
	this->window->draw(this->background);
	this->enemySystem->Render();
	this->player->Render();
	this->camera->Render();
	this->window->display();
}
