#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4
#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

class Menu
{
public:
	Menu();
	~Menu();

	void followMario(int center);
	void draw(sf::RenderWindow& window, int center);
	void drawBestResults(sf::RenderWindow& window, int center);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	bool isON() { return isOn; }
	void setIsON(bool status) { isOn = status;
	selectedItemIndex = 0;
	}


private:
	bool isOn = true;
	int selectedItemIndex=0;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
