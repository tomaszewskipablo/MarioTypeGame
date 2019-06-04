#include "Turtle.h"



Turtle::Turtle()
{
	file = "turtle.png";
	try
	{
		if (!texture.loadFromFile("../assets/" + file, sf::IntRect(0, 0, Height, Width)))
		{
			throw - 1;
		}
	}
	catch (int)
	{
		std::cout << "can not load turtle texture";
		exit(1);
	}

	sprite.setTexture(texture);

	Height = 46;
	Width = 32;
	Velocity = 0.4;
	velocity = { Velocity ,Velocity };
	sprite.setOrigin(Width / 2.f, Height / 2.f);

	isFrendly = false;
}


Turtle::~Turtle()
{
}
