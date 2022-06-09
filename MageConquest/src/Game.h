#pragma once
#include"Player.h"
#include"Camera.h"
#include"EnemySystem.h"


class Game
{
private:
	RenderWindow* window;
	Camera* camera;
	Player* player;
	Sprite background;
	EnemySystem* enemySystem;
	ResourcesManager resManager;
	Event event;
	Clock clock;
	Time deltaTime;
public:
	Game();
	~Game();
	void Run();
	void UpdateEvents();
	void LoadResources();
	void Update();
	void Render();
};

