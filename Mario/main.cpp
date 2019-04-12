#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "tileMap.h"


int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(1024, 512), "Tilemap");

	// create the tilemap 
	TileMap map;
	if (!map.load("../assets/map1.png", sf::Vector2u(64,64), 16, 8))
		return -1;

	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draw the map
		window.clear();
		window.draw(map);
		window.display();
	}

	return 0;
}