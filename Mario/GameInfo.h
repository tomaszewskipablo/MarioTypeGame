#pragma once
#include "SFML/Graphics.hpp"
#include <chrono>
#include<iostream>
using namespace std;
#define NUMBER_OF_ITEMS 3
class GameInfo
{
	int coins=0;
	int time=0;
	int score=0;

	sf::Font font;
	sf::Text info[NUMBER_OF_ITEMS]; 


	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point finish;
	bool difference;
	bool switcher = 0;
public:
	GameInfo();
	~GameInfo();

	void followMario(int center);
	void draw(sf::RenderWindow& window, int center);

	void reset()
	{
		coins = 0;
		time = 0;
		score = 0;
		info[0].setString("Coins: " + std::to_string(coins));
		info[1].setString("Score: " + std::to_string(score));

		finish = start = std::chrono::high_resolution_clock::now();

	}
	void increaseCoins() { coins++;
	increaseScoreCoins();
	info[0].setString("Coins: " + std::to_string(coins));

		}
	void increaseScoreBonus() { score += 50;
	info[1].setString("Score: " + std::to_string(score));
	}
	void increaseScoreCoins() { score += 10;
	info[1].setString("Score: " + std::to_string(score));
	}
	void countTime();
};

