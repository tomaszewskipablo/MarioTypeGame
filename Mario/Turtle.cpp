#include "Turtle.h"



Turtle::Turtle()
{
	file = "turtle.png";
	if (!texture.loadFromFile("../assets/"+file, sf::IntRect(0, 0, Height, Width)))
	{
		std::cout << "Texture did not load " << std::endl;
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
