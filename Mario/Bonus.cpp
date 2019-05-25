#include "Bonus.h"

Bonus::Bonus(sf::Vector2f startingPosition)
{
	file = "bonus.png";
	if (!texture.loadFromFile("../assets/"+file, sf::IntRect(0, 0, Height, Width)))
	{
		std::cout << "Texture did not load " << std::endl;
	}

	sprite.setTexture(texture);
	this->startingPosition = startingPosition;
	sprite.setPosition(startingPosition);

	Height = 32;
	Width = 32;
	Velocity = 0.1;
	velocity = { Velocity ,3*Velocity };
	sprite.setOrigin(Width / 2.f, Height / 2.f);

	isFrendly = true;
}


Bonus::~Bonus()
{
}
