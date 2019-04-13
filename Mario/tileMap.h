#pragma once
#define COIN 2

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include"Mario.h"


class TileMap : public sf::Drawable, public sf::Transformable
{
	int tiles[128] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 4, 0, 0, 2, 2, 2, 0, 0, 4, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 1, 1, 3, 1, 0, 0, 1, 1, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	};

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:

	bool load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height);

	//void update(Mario mario)
	//{
	//	int i = mario.getPosition().x / 64;
	//	int j = mario.getPosition().y / 64;

	//	if(this->tiles[i + j * 16]==)
	//}
};