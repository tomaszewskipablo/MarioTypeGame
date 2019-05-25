#include "Turtle.h"



Turtle::Turtle(sf::Vector2f startingPosition)
{
	if (!texture.loadFromFile("../assets/turtle.png", sf::IntRect(0, 0, Height, Width)))
	{
		std::cout << "Texture did not load " << std::endl;
	}
	
	sprite.setTexture(texture);
	this->startingPosition = startingPosition;
	sprite.setPosition(startingPosition);

	Height = 46;
	Width = 32;
	Velocity = 0.2;
	velocity = { Velocity ,Velocity };
	sprite.setOrigin(Width / 2.f, Height / 2.f);
}


Turtle::~Turtle()
{
}
void Turtle::repair() {
	if (!texture.loadFromFile("../assets/turtle.png", sf::IntRect(0, 0, Height, Width)))
	{
		std::cout << "Texture did not load " << std::endl;
	}

	sprite.setTexture(texture);
}