#pragma once
#include "SFML/Graphics.hpp"
#define NUMBER_OF_ITEMS 3
class GameInfo
{
	int coins=0;
	int time=0;
	int score=0;

	sf::Font font;
	sf::Text info[NUMBER_OF_ITEMS]; 
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
};

