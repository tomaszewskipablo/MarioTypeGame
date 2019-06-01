#pragma once
#include "SFML/Graphics.hpp"
#include<SFML/Window.hpp>
#include <chrono>
#include<iostream>
#include<fstream>
#include<ctime>
#include<algorithm>

#define NUMBER_OF_ITEMS 3
class GameInfo
{
	int coins=0;
	int time=0;
	int score=0;

	sf::Font font;
	sf::Text info[NUMBER_OF_ITEMS]; 

	// time in game
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point finish;
	bool difference;
	bool switcher = 0;

	// save to file
	time_t czas;	// time in seconds count from 1970 year
	std::string localData;	// time in standard format example "Thu Jan 01 01:00:00 1970"
	std::string fileExtension = ".png";
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

	void saveResultToFile();

	std::string properFormat3(int number) // return 3 numbers 3 -> 003, 49 -> 049, 234 -> 234
	{
		if (number < 10)
			return "00" + std::to_string(number);
		else if (number < 100)
			return "0" + std::to_string(number);
		else
			return std::to_string(number);
	}
	std::string properFormat4(int number) // return 4 numbers 3 -> 0003, 49 -> 0049, 234 -> 0234
	{
		if (number < 10)
			return "000" + std::to_string(number);
		else if (number < 100)
			return "00" + std::to_string(number);
		else if (number < 1000)
			return "0" + std::to_string(number);
		else
			return std::to_string(number);
	}
};
