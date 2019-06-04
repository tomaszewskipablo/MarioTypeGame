#include "Mario.h"

Mario::Mario()
{

	file = "mario.png";
	
	try
	{
		if (!texture.loadFromFile("../assets/" + file, sf::IntRect(0, 0, 64, 64)))
		{
			throw - 1;
		}
	}
	catch (int)
	{
		std::cout << "can not load mario texture";
		exit(1);
	}

	sprite.setTexture(texture);
	startingPosition = { 62,128 };
	sprite.setPosition(startingPosition);
	Width = 32;
	Height = 64;
	Velocity = 0.7;
	sprite.setOrigin(Width / 2.f, Height / 2.f);
}


void Mario::update(int mapWidth)
{
	this->sprite.move(this->velocity);


	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
		velocity.x = -Velocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < mapWidth)
		velocity.x = Velocity;
	else
		velocity.x = 0;

	if (Keyboard::isKeyPressed(Keyboard::Key::Up)&& canJump)
		keyRel = true;

	if (keyRel && this->top() > 0 && canJump)
	{
		if (jumpCurrentPossition > jumpHight)
		{
			jumpCurrentPossition = 0;
			canJump = false;
			keyRel = false;
		}
		jumpCurrentPossition++;
		velocity.y = -Velocity * (1 - (jumpCurrentPossition * 1.5) / jumpHight);
	}
	else
	{
		jumpCurrentPossition = 0;
		velocity.y = 0.4;
		canJump = false;
		keyRel = false;
	}
	if (this->bottom() > WINDOW_HIGHT)
	{
		//twice, Mario can be in 2 lives mode, but this should kill him anyway
		this->dead();
		this->dead();
	}
}

void Mario::killingMove() {
	this->sprite.move({ 0,-40 });
}
