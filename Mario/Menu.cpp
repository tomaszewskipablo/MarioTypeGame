#include "Menu.h"


Menu::Menu()
{
	try {
		if (!font.loadFromFile("../assets/arial.ttf"))
		{
			throw - 1;
		}
	}
	catch (int)
	{
		std::cout << "can not load menu font";
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
	readResultsFromFile();
	loadReslutsToArray();


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

	resultsToDisplay[0].setPosition(sf::Vector2f(center - 343, 40));
	resultsToDisplay[1].setPosition(sf::Vector2f(center - 342, 65));
	resultsToDisplay[2].setPosition(sf::Vector2f(center - 341, 90));
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window, int center)
{
	sf::Texture texture;
	try {
		if (!texture.loadFromFile("../assets/menuBack.png"))
		{
			throw - 1;
		}
	}
	catch (int)
	{
		std::cout << "can not load menu background texture texture";
	}
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
void Menu::drawBestResults(sf::RenderWindow & window, int center)
{
	drawBestResultsBackground(window, center);
	drawResults(window, center);
}
void Menu::drawResults(sf::RenderWindow& window, int center)
{
	for (int i = 0; i < NUMBER_OF_RESULTS; i++)
	{
		window.draw(resultsToDisplay[i]);
	}
}
void Menu::drawBestResultsBackground(sf::RenderWindow& window, int center) {
		sf::Texture texture;
	texture.loadFromFile("../assets/bestResultsWindow.png");

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(747 / 2, 103 / 2);
	sprite.setPosition({ (float)center,WINDOW_HIGHT / 6 });
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

void Menu::readResultsFromFile()
{
	std::string line, line2;
	std::string coinsTemp;;
	std::string scoreTemp;
	std::string timeTemp;
	std::ifstream infile;

	infile.open("../results/results.txt");
	if (!infile) {
		std::cout << "can not open file to read results from";
	}
	int counter = 0;

	while (getline(infile, line)) {

		
		getline(infile, line2);

		
		coinsTemp = (std::to_string(line2[7]-48) + std::to_string(line2[8] - 48) + std::to_string(line2[9] - 48));
		scoreTemp = (std::to_string(line2[18] - 48) + std::to_string(line2[19] - 48) + std::to_string(line2[20] - 48) + std::to_string(line2[21] - 48));
		timeTemp = (std::to_string(line2[29] - 48) + std::to_string(line2[30] - 48) + std::to_string(line2[31] - 48));
		
		loadedResults.push_back(result(line, scoreTemp, timeTemp, coinsTemp));

		coinsTemp.clear();
		scoreTemp.clear();
		timeTemp.clear();

		counter++;
		getline(infile, line2);
	}

	infile.close();

	//sort

}
void Menu::loadReslutsToArray()
{
	for (int i = 0; i < NUMBER_OF_RESULTS; i++)
	{
		std::string toDisplay = std::to_string(i + 1) + ". Score: " + loadedResults.at(i).score + " coins: " + loadedResults.at(i).coins + " time " + loadedResults.at(i).time + "   " + loadedResults.at(i).date;
		resultsToDisplay[i].setString(toDisplay);

		resultsToDisplay[i].setFont(font);
		resultsToDisplay[i].setFillColor(sf::Color::Black);
		resultsToDisplay[i].setCharacterSize(25);
	}
}
//bool Menu::comparator(result  i1, result  i2)
//{
//	return (i1.score < i2.score);
//}
//void Menu::sortResults()
//{
//	std::sort(loadedResults.begin(), loadedResults.end(), comparator);
//}
