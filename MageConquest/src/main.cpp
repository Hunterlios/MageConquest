#include"Menu.h"
#include"Game.h"
#include"Help.h"

void LoadResources(ResourcesManager& resManager, Font& font)
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

int main()
{
	ResourcesManager resManager;
	Font font;
	bool displayMenu = true;
	bool displayHelp = false;
	bool displayGame = false;
	LoadResources(resManager, font);
	RenderWindow* window = new RenderWindow(VideoMode(1920, 1080), "MageConquest", Style::Close | Style::Fullscreen);
	window->setKeyRepeatEnabled(true);
	window->setFramerateLimit(60);
	Menu menu(window, font, resManager);
	Help help(window, font, resManager);
	Game* game = nullptr;
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window->close();
				break;
			}
			if (event.type == Event::MouseButtonPressed)
			{
				switch (menu.getPressedItem())
				{
				case 1:
					displayMenu = false;
					displayGame = true;
					displayHelp = false;
					game = new Game(window, resManager, font);
					break;
				case 2:
					displayMenu = false;
					displayHelp = true;
					displayGame = false;
					switch (help.getPressedItem())
					{
					case 1:
						displayHelp = true;
						displayMenu = false;
						displayGame = false;
						break;
					case 2:
						displayHelp = false;
						displayMenu = true;
						displayGame = false;
						break;
					default:
						break;
					}
					break;
				case 3:
					window->close();
					break;
				default:
					break;
				}
			}
		}

		if (displayMenu == true && displayGame == false && displayHelp == false)
		{
			menu.Render();
		}
		else if (displayMenu == false && displayGame == false && displayHelp == true)
		{
			help.Render();
		}
		else if (displayMenu == false && displayGame == true && displayHelp == false)
		{
			game->Run();
		}
	}
	delete window;
	delete game;
}