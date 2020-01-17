#include "Highscore.h"

Highscore::~Highscore()
{
}

void Highscore::show_highscore(sf::RenderWindow & window, int width, int height, Game & GameObj)
{
	sf::Font Font; //zmienna czcionki

	if (!Font.loadFromFile("Sans.ttf")) { throw std::runtime_error("Brak pliku z czionka"); } //zglaszanie wyjatku

	text[0].setCharacterSize(width*height / (scale * 2.77f));
	text[0].setColor(sf::Color::White);
	text[0].setFont(Font);
	text[0].setString("Tablica wynikow:");
	sf::FloatRect text0Rect = text[0].getLocalBounds();
	text[0].setOrigin(text0Rect.left + text0Rect.width / 2.0f, text0Rect.top);
	text[0].setPosition(sf::Vector2f(width / 2.0f, height / 12.0f));

	text[1].setCharacterSize(width*height / (scale * 4.0f));
	text[1].setColor(sf::Color::White);
	text[1].setFont(Font);
	text[1].setString("Wcisnij enter aby wrocic do menu");
	sf::FloatRect text1Rect = text[1].getLocalBounds();
	text[1].setOrigin(text1Rect.left + text1Rect.width / 2.0f, text1Rect.top);
	text[1].setPosition(sf::Vector2f(width / 2.0f, height / 1.3f));


	std::vector<std::pair<std::string, int>> highscores = FileOperations::load(); //wczytanie zwyciêzców z pliku
	int i = 1;
	float j = 12.0f;

	for (std::pair<std::string, int > x : highscores) //wype³nienie tablicy zwyciêzców z pliku
	{
		if (i > 10)
			break;
		winners[i - 1].setCharacterSize(width*height / (scale * 3.0f));
		winners[i - 1].setColor(sf::Color::White);
		winners[i - 1].setFont(Font);
		std::string str = std::to_string(i) + ": " + x.first + " " + std::to_string(x.second);
		winners[i - 1].setString(str);
		sf::FloatRect winnersRect = winners[i - 1].getLocalBounds();
		winners[i - 1].setOrigin(winnersRect.left + winnersRect.width / 2.0f, winnersRect.top);
		winners[i - 1].setPosition(sf::Vector2f(width / 2.0f, (height / 6) + i * 30));
		++i;
	}

	while (window.isOpen()) //pêtla okna
	{
		sf::Event event;

		while (window.pollEvent(event)) //pêtla zdarzeñ
		{
			if (event.type == sf::Event::Closed) //klikniêcie X (w prawym górnym rogu)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				return;
			}
		}

		window.clear();
		for (int i = 0; i < 10; ++i)
		{
			window.draw(winners[i]); //Rysowanie zwyciezcow
		}
		for (int i = 0; i < 2; ++i)
		{
			window.draw(text[i]); //Rysowanie napisow menu
		}
		window.display();
	}
}