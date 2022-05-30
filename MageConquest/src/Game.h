#pragma once
#include"Player.h"
#include"Camera.h"


class Game
{
private:
	RenderWindow* window;
	Camera* camera;
	Player* player;
	TextureLoader* bTexture;
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

