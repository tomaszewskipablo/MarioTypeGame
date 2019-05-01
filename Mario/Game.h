#pragma once

#include"tileMap.h"
#include"Mario.h"
#include"GameInfo.h"
#include "Menu.h"
#include"Screenshot.h"


#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

class Game
{
	Mario mario;
	TileMap map;
	GameInfo gameInfo;
	Menu menu;
	Screenshot screenshot;

	sf::RenderWindow * window;
	sf::Event sfEvent;

public:
	// constructors/destructors
	Game();
	virtual ~Game();

	// functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void Menu();
};

