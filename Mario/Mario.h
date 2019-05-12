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
	float jumpHight = 200;
	float jumpCurrentPossition = 0;
	bool isAlive = true;

public:
	Mario();

	void update();

	void setCanJump(bool canJump) { this->canJump = canJump; }
	void dead() { isAlive = false; }
	bool getIsAlive() { return isAlive; }
};