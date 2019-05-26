#include "tileMap.h"
					
TileMap::TileMap()
{	
	loadArrayFromArray("../assets/array.txt");
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}


bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize)
{
	this->tileSize = tileSize;

	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))	// load tileset to m_tileset texture
		return false;

	// resize the vertex array to fit the map size
	m_vertices.setPrimitiveType(sf::Quads);	// quads for 4 vertices
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex * quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}
int TileMap::collison(Entity & Entity, GameInfo & gameInfo)
{
	float bottom, top, right, left;
	for (unsigned int i = 0; i < height; ++i)
		for (unsigned int j = 0; j < width; ++j)
		{
			if (abs(Entity.getPosition().x - (j * tileSize.x)) <2*tileSize.x&& abs(Entity.getPosition().y - (i * tileSize.y)) < 2*tileSize.y)	// check only fields tileSize
			{
				if (tiles[i * width + j] == 1 || tiles[i * width + j] == 2 || tiles[i * width + j] == 3 || tiles[i * width + j] == 5 || tiles[i * width + j] == 6)
				{
					bottom = i * tileSize.y + tileSize.y;
					top = i * tileSize.y;
					left = j * tileSize.x;
					right = j * tileSize.x + tileSize.x;

					if ((Entity.top() > bottom || Entity.bottom() < top) || (Entity.left() > right || Entity.right() < left)) // Entity doesn't intersect
						;
					else {
						if (tiles[i * width + j] == 1 || tiles[i * width + j] == 3) { // if BRICK OR BONUS
							float tab[4] = { abs(Entity.top() - bottom) , abs(Entity.bottom() - top),  abs(Entity.right() - left),abs(Entity.left() - right) };

							int minumum = min4(tab);
							switch (minumum)
							{
							case BOTTOM:
								if (tiles[i * width + j] == 3) {	// BONUS
									tiles[i * width + j] = 0;
									load("../assets/map.png", sf::Vector2u(64, 64));
									bonus = true;
								}

								if (Entity.getDestroyMode())
								{
									tiles[i * width + j] = 0;
									load("../assets/map.png", sf::Vector2u(64, 64));
								}

								Entity.moveBottom();
								return 0;
							case TOP:
								Entity.moveTop();
								return 1; // Entity touched the ground
							case LEFT:
								Entity.moveLeft();
								return 2;
							case RIGHT:
								Entity.moveRight();
								return 3;
							}
						}
						else if (tiles[i * width + j] == COIN)		// if COIN
						{
							tiles[i * width + j] = 0;	// change coin to heaven
							std::cout << "COINS" << std::endl;
							load("../assets/map.png", sf::Vector2u(64, 64));
							gameInfo.increaseCoins();
						}
						if (tiles[i * width + j] == PLANT || tiles[i * width + j] == PLANT2)		// if PLANT
						{
							std::cout << "COINS" << std::endl;
							Entity.dead();
						}
					}
				}
			}
		}
}

float TileMap::min4(float tab[])
{
	int min = 0;
	for (int i = 1; i < 4; i++)
	{
		if (tab[min] > tab[i])
			min = i;
	}

	return min;
}
void TileMap::loadArrayFromArray(std::string fileName){
	tiles.clear();		

	std::fstream input;
	std::string line;
	int counter = 0;
	int numberOfLines = 0;

	input.open(fileName, std::ios::in);
	if (input.good() == true)
	{
		while (!input.eof())
		{
			numberOfLines++;
			std::getline(input, line);
			width = line.length();

			for (int i = 0; i < width; i++) 
				tiles.push_back(line[i] - '0');

		}
		input.close();
	}
	else
		std::cout << "can not open file " << fileName << std::endl;

	mapWidth = width * 64;
	height = numberOfLines;
}
bool TileMap::onGround(Entity Entity)
{
	float top, left, right;
	for (unsigned int i = 0; i < height; ++i)
		for (unsigned int j = 0; j < width; ++j)
		{
			if (tiles[i * width + j] == 1) {
				top = i * tileSize.y;
				left = j * tileSize.x;
				right = j * tileSize.x + tileSize.x;

				if (abs(Entity.bottom() - top) < 2 && abs(left - Entity.left()) > tileSize.x - 10)	// Entity touch the ground
					return true;
			}
		}
	return false;
}