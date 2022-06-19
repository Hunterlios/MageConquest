#pragma once
#include"PlayerGUI.h"
#include"Camera.h"
#include"EnemySystem.h"

class Game
{
private:
	RenderWindow* window;
	Camera* camera;
	Player* player;
	PlayerGUI* playerGUI;
	Sprite background;
	Font font;
	EnemySystem* enemySystem;
	ResourcesManager resManager;
	Event event;
	Clock clock;
	Time deltaTime;

public:
	Game(RenderWindow* window, ResourcesManager& resManager, Font& font);
	~Game();
	void Run();
	void UpdateEvents();
	void spawnEnemy();
	void Update();
	void Render();
};

