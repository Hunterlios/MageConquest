#pragma once
#include"Menu.h"
class App
{
private:
	RenderWindow* window;
	Event event;
	Clock clock;
	float deltaTime;
	ResourcesManager resManager;
	Font font;
	Menu* menu;
	Help* help;
	Game* game;
	GameOver* gameOver;
	stack<State*> states;
	bool gameRunning, helpRunning, gameOverRunning, gameOverPushed, playerAlive;
	
public:
	void LoadResources();
	void Run();
	void UpdateEvents();
	void Update();
	void Render();
	App();
	~App();
};

