#include "Game.h"
#include<iostream>


Game::Game()
{
	// window initialization
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "SUPER Entity");

	map.load("../assets/map1.png", sf::Vector2u(64, 64));

	view.reset(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH, WINDOW_HIGHT));

	gameInfo.reset();

}


Game::~Game()
{
	delete this->window;
}


void Game::intersection(Mario& mario, Entity& entity)
{
	if (entity.getIsAlive()) {
		if (mario.getSprite().getGlobalBounds().intersects(entity.getSprite().getGlobalBounds()))
			if (abs(mario.bottom() - entity.top()) < 10 && abs(mario.left() - entity.left()) < 54)	// mario jumped on the turtle
			{
				if (mario.getIsAlive())
				{
					mario.killingMove();
					entity.dead();
				}
			}
			else
			{
				if (entity.getIsAlive())
				{
					mario.dead();
					menu.setIsON(true);
				}
			}
	}
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

	intersection(mario, turtle);

	if (turtle.getIsAlive())
	{
		int movingSide = map.collison(turtle, gameInfo);

		if (movingSide == LEFT)
			turtle.MovingDirectiongLeft();
		else if (movingSide == RIGHT)
			turtle.MovingDirectiongRight();

		turtle.update();
	}
	if (mario.getIsAlive()) {
		if (map.collison(mario, gameInfo) == BOTTOM)	// if mario on the ground he can jump
			mario.setCanJump(true);
		mario.update(map.getMapWidth());
	}

}

void Game::render()
{
	this->window->clear();
	// render items
	window->draw(map);

	if (mario.getIsAlive())
		window->draw(mario);
	if (turtle.getIsAlive())
		window->draw(turtle);

	cameraMovement();

	window->setView(view);
	this->window->display();
}
void Game::Menu(int center)
{
	if (center < WINDOW_WIDTH / 2)
		center = WINDOW_WIDTH / 2;

	menu.followMario(center);
	menu.draw(*window, center);
	if (menu.GetPressedItem() == 2)
	{
		menu.drawBestResults(*window, center);
	}
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
				{
					mario.reset();
					turtle.reset();
					view.reset(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH, WINDOW_HIGHT));
					map.loadArrayFromArray("../assets/array.txt");
					map.load("../assets/map1.png", sf::Vector2u(64, 64));
					menu.setIsON(false);
				}
				if (menu.GetPressedItem() == 2)
				{
					std::cout << "BEST restult smlksadnlsan102" << std::endl;
				}
				if (menu.GetPressedItem() == 3)
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
			Menu(mario.getPosition().x);
		else {
			this->update();
			this->render();
		}
	}
}
void Game::cameraMovement() {
	if(mario.getPosition().x > WINDOW_WIDTH/2)
		view.setCenter({mario.getPosition().x, WINDOW_HIGHT/2});
}