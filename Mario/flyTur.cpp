#include "FlyTur.h"



FlyTur::FlyTur()
{
	file = "FlyTur.png";
	if (!texture.loadFromFile("../assets/" + file, sf::IntRect(0, 0, Height, Width)))
	{
		std::cout << "Texture did not load " << std::endl;
	}

	sprite.setTexture(texture);

	Height = 48;
	Width = 32;
	Velocity = 0.4;
	velocity = { Velocity , 0 };
	sprite.setOrigin(Width / 2.f, Height / 2.f);

	isFrendly = false;
}


FlyTur::~FlyTur()
{
}
