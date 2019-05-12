#include "Game.h"
#include<iostream>


Game::Game()
{
	// window initialization
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "SUPER MARIO");

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
		if (this->sfEvent.type == sf::Event::KeyReleased)
		{
			if (sfEvent.key.code == Keyboard::Escape)
			{
				std::cout << "ESCAPE()" << std::endl;
				menu.setIsON(true);
			}
			// screen shots
			if (sfEvent.key.code == Keyboard::F1)
			{
				screenshot.create(window);
			}
		}
	}
}

void Game::update()
{
	this->updateSFMLEvents();

	if (map.collison(mario))
		mario.setCanJump(true);
	//if (map.onGround(mario))
		

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
void Game::Menu()
{
	
	menu.draw(*window);
	this->window->display();
		while (window->pollEvent(sfEvent))
		{
			if (sfEvent.type == Event::Closed)
				window->close();

			if (sfEvent.type == Event::KeyReleased)
			{
				if (sfEvent.key.code == Keyboard::Up)
				{
					menu.MoveUp();
					std::cout << "MoveUp()" << std::endl;
				}
				if (sfEvent.key.code == Keyboard::Down)
				{
					menu.MoveDown();
					std::cout << "MoveDown()" << std::endl;
				}
				if (sfEvent.key.code == Keyboard::Enter)
				{
					std::cout << "Enter()" << std::endl;
					if (menu.GetPressedItem() == 0)
						menu.setIsON(false);
					if (menu.GetPressedItem() == 1)
						std::cout << "BEST restult smlksadnlsan102" << std::endl;
					if (menu.GetPressedItem() == 2)
					{
						window->close();
						delete this->window;
						exit(0);
					}
				}
			}
	}
}


void Game::run()
{

	while (this->window->isOpen())
	{
		if (menu.isON())
			Menu();
		else {
			this->update();
			this->render();
		}
	}
}