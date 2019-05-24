#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"entity.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

using namespace sf;
class Mario : public Entity
{
private:

	bool canJump = 0;
	float jumpHight = 400;
	float jumpCurrentPossition = 0;

public:
	Mario();

	void update(int mapWidth);
	void killingMove();

	void setCanJump(bool canJump) { this->canJump = canJump; }
};