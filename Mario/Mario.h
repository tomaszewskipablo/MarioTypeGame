#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <chrono>
#include <string>
#include"entity.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

using namespace sf;

class Mario : public Entity
{
private:

	bool canJump = 0;
	float jumpHight = 600;
	float jumpCurrentPossition = 0;
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point finishTime;

	bool bigMario = false;
	std::string fileBigMario = "bigMario.png";

	sf::Clock clock;
	float flPreviousTime = 0;
	float flCurrentTime = 0;
	float dt;

	bool keyRel = false;
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
	float getCurrentTime()
	{
		return clock.getElapsedTime().asMilliseconds();
	}
	void fallDown()
	{
		this->keyRel = false;
	}
};