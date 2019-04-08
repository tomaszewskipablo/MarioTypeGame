#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Entity.h"
class tileMap
{
	Entity* tile_map[8][8];

public:
	tileMap();
	~tileMap();
};

