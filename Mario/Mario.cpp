#include "Mario.h"

Mario::Mario()
{
	if (!texture.loadFromFile("../assets/mario.png", sf::IntRect(0, 0, 64, 64)))
	{
		// error...
	}
	sprite.setTexture(texture);
	sprite.setPosition(62,128);
	sprite.setOrigin(MarioWidth / 2.f, MarioHeight / 2.f);
}
void Mario::draw(RenderTarget & target, RenderStates state)const {
	target.draw(this->sprite, state);
}

Vector2f Mario::getPosition()
{
	return sprite.getPosition();
}


void Mario::update()
{
	this->sprite.move(this->velocity); // gets vector vector(x,y) 


	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
		velocity.x = -MarioVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < WINDOW_WIDTH)
		velocity.x = MarioVelocity;
	else
		velocity.x = 0;

	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0)
		velocity.y = -MarioVelocity;
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < WINDOW_HIGHT)
		velocity.y = MarioVelocity;
	else
		velocity.y = 0;

}
float Mario::left()
{
	return this->sprite.getPosition().x - 32 / 2.f;
}
float Mario::right()
{
	return this->sprite.getPosition().x + 32/ 2.f;
}
float Mario::top()
{
	return this->sprite.getPosition().y - 64 / 2.f;
}
float Mario::bottom()
{
	return this->sprite.getPosition().y + 64 / 2.f;
}

