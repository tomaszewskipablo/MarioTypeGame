#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3
#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

class Menu
{
public:
	Menu();
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	bool isON() { return isOn; }
	void setIsON(bool status) { isOn = status; }

private:
	bool isOn = true;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
