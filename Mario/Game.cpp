#include "Game.h"



Game::Game()
{
	// window initialization
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "BACKYARD GAME");

	map.load("../assets/map1.png", sf::Vector2u(64, 64), 16, 8);

	gameInfo.reset();

}


Game::~Game()
{
	delete this->window;
}



void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateSFMLEvents();

	
	mario.update();
}

void Game::render()
{
	this->window->clear();
	// render items
	window->draw(map);
	window->draw(mario);


	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}