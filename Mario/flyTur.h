#pragma once

#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include"entity.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

using namespace sf;
class FlyTur : public Entity
{
private:

public:
	FlyTur();
	//	FlyTur(sf::Vector2f startingPosition);
	~FlyTur();
};
