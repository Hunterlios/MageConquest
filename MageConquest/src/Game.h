#pragma once
#include"PlayerGUI.h"
#include"Camera.h"
#include"EnemySystem.h"
#include"State.h"

class Game : public State
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
	float deltaTime;

public:
	Game(RenderWindow* window, ResourcesManager& resManager, Font& font);
	virtual ~Game();
	bool isPlayerDead();
	int getPlayerScore();
	void spawnEnemy();
	void Update(float& deltaTime);
	void Render();
};

