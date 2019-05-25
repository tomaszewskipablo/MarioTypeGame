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
	bool bigMario = false;
	std::string fileBigMario = "bigMario.png";

public:
	Mario();

	void update(int mapWidth);
	void killingMove();

	void setCanJump(bool canJump) { this->canJump = canJump; }
	bool isBig() { return bigMario; }
	void setBigMario(bool isBig) { 
		if (bigMario = isBig)
		{
			sprite.setScale(1.3, 1);
			Width *= 1.3;
		}
		else 
		{
			sprite.setScale(32/Width, 1);
			Width = 32;
		}
	}
	void dead() {
		
		if (bigMario) {
			setBigMario(false);
			reset();
		}
		else
			isAlive = false;
	}
};