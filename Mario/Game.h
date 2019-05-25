#pragma once

#include"tileMap.h"
#include"Entity.h"
#include"Mario.h"
#include"Turtle.h"
#include"GameInfo.h"
#include "Menu.h"
#include"Screenshot.h"
#include"Bonus.h"


#include<typeinfo>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3

class Game
{
	Mario mario;
	std::vector<Entity> mobs;
	//Bonus bonus;
	TileMap map;
	GameInfo gameInfo;
	Menu menu;
	Screenshot screenshot;
	sf::View view;

	sf::RenderWindow * window;
	sf::Event sfEvent;

public:
	// constructors/destructors
	Game();
	virtual ~Game();

	// functions
	void intersection(Mario &mario, Entity &entity);
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void Menu(int center);
	void cameraMovement();
	void repairSFMLTextures();
	void drawMobs();
	void Bonuses();
	void addMobs();
};

