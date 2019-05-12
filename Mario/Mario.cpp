#include "Mario.h"

Mario::Mario()
{
	if (!texture.loadFromFile("../assets/mario.png", sf::IntRect(0, 0, 64, 64)))
	{
		// error...
	}
	sprite.setTexture(texture);
	sprite.setPosition(62, 128);
	Width = 32;
	Height = 64;
	Velocity = 0.7;
	sprite.setOrigin(Width / 2.f, Height / 2.f);
}


void Mario::update()
{
	this->sprite.move(this->velocity);


	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
		velocity.x = -Velocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < WINDOW_WIDTH)
		velocity.x = Velocity;
	else
		velocity.x = 0;

	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0 && canJump)
	{
		if (jumpCurrentPossition > jumpHight)
		{
			jumpCurrentPossition = 0;
			canJump = false;
		}
		jumpCurrentPossition++;
		velocity.y = -Velocity;
	}
	else
		velocity.y = 0.3;
	//
}
