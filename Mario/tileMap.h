#pragma once
#define COIN 2

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include"Mario.h"
#include<iostream>
#include <algorithm>

#define BOTTOM 0
#define TOP 1
#define LEFT 2
#define RIGHT 3

class TileMap : public sf::Drawable, public sf::Transformable
{
	int tiles[128] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 4, 0, 0, 2, 2, 2, 0, 0, 4, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
		1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	sf::Vector2u tileSize;
	unsigned int width;
	unsigned int height;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);
	bool collison(Mario &mario);
	float min4(float tab[]);
	bool onGround(Mario mario);
};