#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::loadTexture()
{
	if (!texture.loadFromFile(textureSource))
	{
		// error...
	}
	sprite.setTexture(texture);
}
void Entity::setPosition()
{
	sprite.setPosition(Height, Width);
}