#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"Entity.h"
#include "tileMap.h"

int main()
{

	RenderWindow window{ VideoMode{800,600},"my window" };
	window.setFramerateLimit(60);


	Event event;
	while (true)
	{


		window.clear(Color::Black);
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
	}
	return 0;
}