#pragma once
#define COIN 2

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include"Entity.h"
#include"GameInfo.h"
#include<fstream>
#include<iostream>
#include <stdio.h>
#include<vector>


#define BOTTOM 0
#define TOP 1
#define LEFT 2
#define RIGHT 3

class TileMap : public sf::Drawable, public sf::Transformable
{
	std::vector<int> tiles; 


	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	sf::Vector2u tileSize;
	unsigned int width;
	unsigned int height;
	unsigned int mapWidth;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool bonus;
public:
	TileMap();
	bool load(const std::string& tileset, sf::Vector2u tileSize);
	int collison(Entity &Entity, GameInfo &gameInfo);	// function returns from what side collision comes from and move object to the opposit side
	float min4(float tab[]);
	void loadArrayFromArray(std::string fileName);
	bool onGround(Entity Entity);
	int getMapWidth() { return mapWidth; }
	bool getBonus() { return bonus; }
	void setBonus(bool bonus) { this->bonus = bonus; }
};