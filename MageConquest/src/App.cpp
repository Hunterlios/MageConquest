#include "App.h"

void App::LoadResources()
{
	font.loadFromFile("./resources/PressStart2P-Regular.ttf");
	resManager.LoadTexture("playerTexture", PLAYER_TEXTURE);
	resManager.LoadTexture("background", BACKGROUND);
	resManager.LoadTexture("ratTexture", RAT_TEXTURE);
	resManager.LoadTexture("fireball", FIREBALL_TEXTURE);
	resManager.LoadTexture("goblinTexture", GOBLIN_TEXTURE);
	resManager.LoadTexture("skeletonTexture", SKELETON_TEXTURE);
	resManager.LoadTexture("vampireTexture", VAMPIRE_TEXTURE);
	resManager.LoadTexture("menuBackground", MENU_BACKGROUND);
}

void App::Run()
{
	while (this->window->isOpen())
	{
		this->UpdateEvents();
		this->Update();
		this->Render();
	}
}

void App::UpdateEvents()
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
		

		if (this->event.type == Event::MouseButtonPressed)
		{
			if (Mouse::isButtonPressed(Mouse::Button::Left))
			{
				if (!gameRunning && !helpRunning && !gameOverRunning)
				{
					switch (menu->getPressedItem())
					{
					case 1:
						this->game = new Game(this->window, this->resManager, this->font);
						this->states.push(game);
						this->playerAlive = true;
						this->gameRunning = true;
						break;
					case 2:
						this->help = new Help(this->window, this->font, this->resManager);
						this->states.push(help);
						this->helpRunning = true;
						break;
					case 3:
						this->window->close();
						break;
					default:
						break;
					}
				}
				
				if (!gameRunning && helpRunning && !gameOverRunning)
				{
					switch (help->getPressedItem())
					{
					case 1:
						continue;
					case 2:
						delete this->states.top();
						this->states.pop();
						this->helpRunning = false;
						break;
					default:
						break;
					}
				}

				if (!gameRunning && !helpRunning && gameOverRunning)
				{		
					switch (gameOver->getPressedItem())
					{
					case 1:
						continue;
					case 2:
						this->window->close();
					default:
						break;
					}

				}
				
			}
		}
	}
}

void App::Update()
{
	this->deltaTime = clock.restart().asSeconds();
	if (!this->states.empty())
	{
		this->states.top()->Update(deltaTime);
	}
	if (this->playerAlive)
	{
		if (this->game->isPlayerDead())
		{
			this->playerAlive = false;
			this->gameOverRunning = true;
			this->gameRunning = false;
		}
	}
	if (!gameRunning && !helpRunning && gameOverRunning)
	{
		if (!gameOverPushed)
		{
			this->gameOver = new GameOver(this->window, this->font, this->resManager, this->game->getPlayerScore());
			delete this->states.top();
			this->states.pop();
			this->states.push(gameOver);
			this->gameOverPushed = true;
		}
	}
}

void App::Render()
{
	this->window->clear();
	if (!this->states.empty())
	{
		this->states.top()->Render();
	}
	this->window->display();
}

App::App()
{
	this->LoadResources();
	this->deltaTime = {};
	this->gameRunning = false;
	this->helpRunning = false;
	this->gameOverRunning = false;
	this->gameOverPushed = false;
	this->playerAlive = false;
	this->window = new RenderWindow(VideoMode(1920, 1080), "MageConquest", Style::Close | Style::Fullscreen);
	this->window->setKeyRepeatEnabled(true);
	this->window->setFramerateLimit(60);
	this->event = Event();
	this->menu = new Menu(this->window, this->font, this->resManager);
	this->states.push(menu);
	
}

App::~App()
{
	delete this->window;
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}
