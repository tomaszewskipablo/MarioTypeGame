#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
#include<fstream>
#include <algorithm>    
#include <vector>       

#define MAX_NUMBER_OF_ITEMS 4
#define NUMBER_OF_RESULTS 3
#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512


class result {
public:
	std::string date;
	std::string score;
	std::string time;
	std::string coins;
	result(std::string date, std::string score,std::string time,std::string coins) :date(date), score(score),time(time),coins(coins){};
};

class Menu
{
private:
	bool isOn = true;
	int selectedItemIndex = 0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

	std::vector<result> loadedResults;
	sf::Text resultsToDisplay[NUMBER_OF_RESULTS];

public:
	Menu();
	~Menu();

	void followMario(int center);
	void draw(sf::RenderWindow& window, int center);
	void drawBestResults(sf::RenderWindow& window, int center);
	void drawResults(sf::RenderWindow& window, int center);
	void drawBestResultsBackground(sf::RenderWindow& window, int center);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	void setPressedItem(int item) { selectedItemIndex = item; }
	bool isON() { return isOn; }
	void setIsON(bool status) { isOn = status;
	selectedItemIndex = 0;
	}
	void readResultsFromFile();
	void loadReslutsToArray();
	bool comparator(result i1, result i2);
	void sortResults();

	void gameWon(int center, sf::RenderWindow& window);
	void reset() {
		selectedItemIndex = 0;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	menu[selectedItemIndex+1].setFillColor(sf::Color::Black);
	}
};
