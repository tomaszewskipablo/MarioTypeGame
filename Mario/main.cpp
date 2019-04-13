#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "tileMap.h"
#include "Mario.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "Mario Boss");

	// create the tilemap 
	TileMap map;
	if (!map.load("../assets/map1.png", sf::Vector2u(64,64), 16, 8))
		return -1;
	Mario mario(128,256);

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
		window.draw(mario);
		mario.update();
		window.display();

		/*map.upadte(mario);*/
	}

	return 0;
}