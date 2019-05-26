#include "Game.h"
#include<iostream>


Game::Game()
{
	// window initialization
	this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "SUPER Entity");

	map.load("../assets/map1.png", sf::Vector2u(64, 64));

	view.reset(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH, WINDOW_HIGHT));

	gameInfo.reset();

	addMobs();

}


Game::~Game()
{
	delete this->window;
}


void Game::intersection(Mario& mario, Entity& entity)
{
	Bonus b;
	if (entity.getIsAlive()) {
		if (mario.getSprite().getGlobalBounds().intersects(entity.getSprite().getGlobalBounds()))
			if (entity.getIsFrendly())
			{
				entity.dead();
				mario.setBigMario(true);
				gameInfo.increaseScoreBonus();
			}
			else
			{
				if (abs(mario.bottom() - entity.top()) < 10 && abs(mario.left() - entity.left()) < 54)	// mario jumped on the entity
				{
					if (mario.getIsAlive())
					{
						mario.killingMove();
						entity.dead();
						gameInfo.increaseScoreBonus();
					}
				}
				else
				{
					if (entity.getIsAlive())
					{
						menu.setIsON(true);
						mario.killingMove();
						mario.killingMove();
						mario.dead();
						if (mario.getIsAlive()) {
							menu.setIsON(false);
							view.setCenter(WINDOW_WIDTH/2,WINDOW_HIGHT/2);
						}
						
					}
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

	for (int i = 0; i < mobs.size(); i++)
	{
		intersection(mario, mobs.at(i));

		if (mobs.at(i).getIsAlive())
		{
			int movingSide = map.collison(mobs.at(i), gameInfo);

			if (movingSide == LEFT)
				mobs.at(i).MovingDirectiongLeft();
			else if (movingSide == RIGHT)
				mobs.at(i).MovingDirectiongRight();

			mobs.at(i).update();
		}
	}

	menu.followMario(mario.getPosition().x);
	
		if (map.collison(mario, gameInfo) == BOTTOM)	// if mario on the ground he can jump
			mario.setCanJump(true);
		mario.update(map.getMapWidth());

		
	if (!mario.getIsAlive())
		menu.setIsON(true);

	Bonuses();
}

void Game::render()
{
	this->window->clear();
	// render items

	window->draw(map);


	this->gameInfo.followMario(view.getCenter().x);
	this->gameInfo.draw(*window, view.getCenter().x);

	if (mario.getIsAlive())
		window->draw(mario);

	drawMobs();

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
					mario.setBigMario(false);
					addMobs();

					view.reset(sf::FloatRect(0.f, 0.f, WINDOW_WIDTH, WINDOW_HIGHT));
					gameInfo.reset();
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
			Menu(view.getCenter().x);
		else {
			this->update();
			this->render();
		}

		
	}
}
void Game::cameraMovement() {
	if (mario.getPosition().x > WINDOW_WIDTH / 2)
		view.setCenter({ mario.getPosition().x, WINDOW_HIGHT / 2 });
}
void Game::repairSFMLTextures()
{
	for (int i = 0; i < mobs.size(); i++)
	{
		mobs.at(i).repair();
	}
}
void Game::drawMobs()
{
	for (int i = 0; i < mobs.size(); i++)
	{
		if (mobs[i].getIsAlive())
			window->draw(mobs.at(i));
	}
}
void Game::Bonuses()
{
	if (map.getBonus() == true)
	{
		Bonus bonus({ mario.getPosition().x - 100, mario.getPosition().y - 128 });
		mobs.push_back(bonus);

		repairSFMLTextures();
		map.setBonus(false);
	}
}
void Game::addMobs()
{
	mobs.clear();
	// ------------------- ADD MOBS HERE ----------------------
	Turtle turtle1({ 400,400 });
	Turtle turtle2({ 1400,100 });


	mobs.push_back(turtle1);
	mobs.push_back(turtle2);


	repairSFMLTextures();
	// ---------------------------------------------------------
}