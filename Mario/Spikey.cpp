#include "Spikey.h"



Spikey::Spikey(sf::Vector2f startingPosition)
{
	file = "Spikey.png";
	if (!texture.loadFromFile("../assets/" + file, sf::IntRect(0, 0, Height, Width)))
	{
		std::cout << "Texture did not load " << std::endl;
	}

	sprite.setTexture(texture);
	this->startingPosition = startingPosition;
	sprite.setPosition(startingPosition);

	Height = 32;
	Width = 32;
	Velocity = 0.2;
	velocity = { Velocity ,Velocity };
	sprite.setOrigin(Width / 2.f, Height / 2.f);

	isFrendly = false;
	killable = false;
}


Spikey::~Spikey()
{
}
