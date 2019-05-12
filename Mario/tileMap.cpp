#include "tileMap.h"

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}


bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
	this->tileSize = tileSize;
	this->width = width;
	this->height = height;

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
bool TileMap::collison(Mario & mario)
{
	float bottom, top, right, left;
	for (unsigned int i = 0; i < height; ++i)
		for (unsigned int j = 0; j < width; ++j)
		{
			if (tiles[i * width + j] == 1)
			{
				bottom = i * tileSize.y + tileSize.y;
				top = i * tileSize.y;
				left = j * tileSize.x;
				right = j * tileSize.x + tileSize.x;

				if ((mario.top() > bottom || mario.bottom() < top) || (mario.left() > right || mario.right() < left)) // mario doesn't intersect
					;
				else {
					float tab[4] = { abs(mario.top() - bottom) , abs(mario.bottom() - top),  abs(mario.right() - left),abs(mario.left() - right) };

					//	std::cout << "Bottom " << aBottom << "  " << "aTop " << aTop << " left " << aLeft << " right " << aRight << std::endl;
						// znajdziemy minimum i w tą strone ruszymy maria
						//std::cout << std::endl << min4(aTop, aBottom, aLeft, aRight);
					int minumum = min4(tab);
					switch (minumum)
					{
					case BOTTOM:
						mario.moveBottom();
						break;
					case TOP:
						mario.moveTop();
						return true; // mario touched the ground
					case LEFT:
						mario.moveLeft();
						break;
					case RIGHT:
						mario.moveRight();
						break;
					}
					//	std::cout << "Collison";
					break;
				}
			}
		}
	return false;
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
bool TileMap::onGround(Mario mario)
{
	float top, left, right;
	for (unsigned int i = 0; i < height; ++i)
		for (unsigned int j = 0; j < width; ++j)
		{
			if (tiles[i * width + j] == 1) {
				top = i * tileSize.y;
				left = j * tileSize.x;
				right = j * tileSize.x + tileSize.x;

				if (abs(mario.bottom() - top) <2 && abs(left - mario.left()) > tileSize.x-10)	// mario touch the ground
					return true;
			}
		}
	return false;
}