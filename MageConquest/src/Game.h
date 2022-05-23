#pragma once
#include"TextureLoader.h"
#include"Player.h"
#include"Camera.h"


class Game
{
private:
	RenderWindow* window;
	TextureLoader* backgroundTexture;
	Camera* camera;
	Player* player;
	Event event;
	Clock clock;
	Time deltaTime;
public:
	Game();
	~Game();
	void Run();
	void UpdateEvents();
	void Update();
	void Render();
};

