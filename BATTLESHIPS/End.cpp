#include "End.h"
#include "FileOperations.h"




End::~End()
{
}


void End::show_ending_screen(sf::RenderWindow & window, int width, int height, Game & GameObj, bool player)
{
	sf::Font Font;

	if (!Font.loadFromFile("Sans.ttf")) { throw std::runtime_error("Brak pliku z czionka"); } //zglaszanie wyjatku

	std::string str = ""; //string z nazw¹ wygranego
	sf::Text end, nickname;

	if (player) //napis w przypadku wygranej
	{
		end.setCharacterSize(width*height / (scale * 2.77f));
		end.setColor(sf::Color::White);
		end.setFont(Font);
		end.setString("WYGRALES!\n Wpisz swoj nick i zatwierdz klawiszem enter!");
		sf::FloatRect endRect = end.getLocalBounds();
		end.setOrigin(endRect.left + endRect.width / 2.0f, endRect.top);
		end.setPosition(sf::Vector2f(width / 2.0f, height / 12.0f));

		nickname.setCharacterSize(width*height / 25000);
		nickname.setColor(sf::Color::White);
		nickname.setFont(Font);
		sf::FloatRect nicknameRect = nickname.getLocalBounds();
		nickname.setOrigin(nicknameRect.left + nicknameRect.width / 2.0f, nicknameRect.top);
		nickname.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));

	}
	else //napis w przypadku przegranej
	{
		end.setCharacterSize(width*height / (scale * 2.77f));
		end.setColor(sf::Color::White);
		end.setFont(Font);
		end.setString("PRZEGRALES!\n Wcisnij klawisz enter aby wyjsc");
		sf::FloatRect endRect = end.getLocalBounds();
		end.setOrigin(endRect.left + endRect.width / 2.0f, endRect.top);
		end.setPosition(sf::Vector2f(width / 2.0f, height / 12.0f));
	}

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !player)
			{
				window.close();
			}

			if (player)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					//ZAPIS DO PLIKU
					FileOperations::save(GameObj.get_humanCounter(), str);
					window.close();
				}
				if (event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode < 128) //dopisywanie nicku wygranego do stringa i wyœwietlanie go
					{
						str += static_cast<char>(event.text.unicode);
						nickname.setString(str);
						sf::FloatRect nicknameRect = nickname.getLocalBounds();
						nickname.setOrigin(nicknameRect.left + nicknameRect.width / 2.0f, nicknameRect.top);
						nickname.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));
					}
				}
			}
		}
		//RYSOWANIE
		window.clear();
		window.draw(end);
		if (player)
			window.draw(nickname);

		window.display();
	}
}