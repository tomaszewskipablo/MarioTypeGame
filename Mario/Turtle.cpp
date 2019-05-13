#include "Turtle.h"



Turtle::Turtle()
{
	if (!texture.loadFromFile("../assets/turtle.png", sf::IntRect(0, 0, Height, Width)))
	{
		// error...
	}
	sprite.setTexture(texture);
	startingPosition = { 300,400 };
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
