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

	void setCanJump(bool canJump);

	bool isBig();

	void setBigMario(bool isBig);

	void dead();

	float getCurrentTime();

	void fallDown();
};