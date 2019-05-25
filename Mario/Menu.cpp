#include "Menu.h"


Menu::Menu()
{
	if (!font.loadFromFile("../assets/arial.ttf"))
	{
		// handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Restart");
	

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Options");
	

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("Exit");
	
	selectedItemIndex = 0;
}
void Menu::followMario(int center) {
	menu[0].setPosition(sf::Vector2f(center - 26, WINDOW_HIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1.25 + 45));
	menu[1].setPosition(sf::Vector2f(center - 45, WINDOW_HIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 1.6 + 45));
	menu[2].setPosition(sf::Vector2f(center - 45, WINDOW_HIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2 + 45));
	menu[3].setPosition(sf::Vector2f(center - 20, WINDOW_HIGHT / (MAX_NUMBER_OF_ITEMS + 1) * 2.4 + 45));
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window, int center)
{
	sf::Texture texture;
	texture.loadFromFile("../assets/menuBack.png");
	//display background
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin({ 190,101 });
	sprite.setPosition({ (float)center,WINDOW_HIGHT / 2 });
	window.draw(sprite);

	//display option to choose
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	
}
void Menu::drawBestResults(sf::RenderWindow& window, int center)
{
	sf::Texture texture;
	texture.loadFromFile("../assets/bestResultsWindow.png");
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(747/2, 103/2);
	sprite.setPosition({ (float)center,WINDOW_HIGHT /6});
	window.draw(sprite);
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}