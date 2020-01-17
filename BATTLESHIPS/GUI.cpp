#include <iostream>
#include <algorithm>
#include "GUI.h"
#include "Coords.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "Highscore.h"
#include "End.h"
#define SCALE 9000.0f
#define SCALE2 25000.0f
#define NUMBER_OF_SHIPS 5

sf::RectangleShape drawSquare(float width = 1.0f, float height = 1.0f, sf::Vector2f position = sf::Vector2f(0, 0))
{
	sf::RectangleShape Square;
	sf::Vector2f myRectangleSize(width, height);
	Square.setSize(myRectangleSize);
	Square.setPosition(position);
	Square.setFillColor(sf::Color::White);
	Square.setOutlineColor(sf::Color::Black);
	Square.setOutlineThickness(-2);
	return Square;
}

GUI::GUI(Game & GameObj, int width, int height, int map, int ships)
{
	map_size = map;
	number_of_ships = ships;
	int playerX = width / 16.0f;
	int playerY = height / 8.0f;
	int enemyX = width / 1.6f;
	int enemyY = height / 8.0f;
	for (int i = 0; i < map_size; i++)
	{
		for (int j = 0; j < map_size; j++)
		{
			PlayerGrid[i][j] = drawSquare(width / 16.0f, height / 12.0f, sf::Vector2f(playerX, playerY));
			PlayerGrid[i][j].setFillColor(sf::Color::Black);
			PlayerGrid[i][j].setOutlineColor(sf::Color(51, 102, 153));
			playerX += width / 16.0f + 1;
		}
		playerY += height / 12.0f + 1;
		playerX = width / 16.0f;
	}
	for (int i = 0; i < map_size; i++)
	{
		for (int j = 0; j < map_size; j++)
		{
			EnemyGrid[i][j] = drawSquare(width / 16.0f, height / 12.0f, sf::Vector2f(enemyX, enemyY));
			EnemyGrid[i][j].setFillColor(sf::Color::White);
			EnemyGrid[i][j].setOutlineColor(sf::Color(0, 51, 102));
			enemyX += width / 16.0f + 1;
		}
		enemyY += height / 12.0f + 1;
		enemyX = width / 1.6f;
	}
}
GUI::~GUI()
{

}

void GUI::computerScored(const Coords & coords) //implementacja funkcji wirtualnej, pokazuje na ekranie trafienie komputera
{
	int x = coords.get_x();
	int y = coords.get_y();

	PlayerGrid[x][y].setFillColor(sf::Color::Red);
	PlayerGrid[x][y].setOutlineColor(sf::Color::Black);
}
void GUI::computerMissed(const Coords & coords) //implementacja funkcji wirtualnej, pokazuje na ekranie, gdy komputer nie trafil
{
	int x = coords.get_x();
	int y = coords.get_y();

	PlayerGrid[x][y].setFillColor(sf::Color::Green);
	PlayerGrid[x][y].setOutlineColor(sf::Color::Black);
}
void GUI::humanScored(const Coords & coords) //implementacja funkcji wirtualnej, pokazuje na ekranie trafienie gracza ludzkiego
{
	int x = coords.get_x();
	int y = coords.get_y();

	EnemyGrid[x][y].setFillColor(sf::Color::Red);
	EnemyGrid[x][y].setOutlineColor(sf::Color::Black);
}

void GUI::humanMissed(const Coords & coords) //implementacja funkcji wirtualnej, pokazuje na ekranie, gdy gracz ludzki nie trafil
{
	int x = coords.get_x();
	int y = coords.get_y();

	EnemyGrid[x][y].setFillColor(sf::Color::Green);
	EnemyGrid[x][y].setOutlineColor(sf::Color::Black);
}

void GUI::drawMenu(sf::RenderWindow & window, int width, int height, Game & GameObj)
{
	sf::Font Font; //zmienna czcionki

	if (!Font.loadFromFile("Sans.ttf")) { throw std::runtime_error("Brak pliku z czionka"); } //zglaszanie wyjatku

	//Napis "graj"
	menu[0].setCharacterSize(width*height/SCALE);
	menu[0].setColor(sf::Color::White);
	menu[0].setFont(Font);
	menu[0].setString("Graj");
	sf::FloatRect menu0Rect = menu[0].getLocalBounds();
	menu[0].setOrigin(menu0Rect.left + menu0Rect.width / 2.0f, menu0Rect.top);
	menu[0].setPosition(sf::Vector2f(width / 2.0f, height / 12.0f));

	//Napis "tablica wynikow"
	menu[1].setCharacterSize(width*height / SCALE);
	menu[1].setColor(sf::Color::White);
	menu[1].setFont(Font);
	menu[1].setString("Tablica Wynikow");
	sf::FloatRect menu1Rect = menu[1].getLocalBounds();
	menu[1].setOrigin(menu1Rect.left + menu1Rect.width / 2.0f, menu1Rect.top);
	menu[1].setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));

	//Napis "wyjdz"
	menu[2].setCharacterSize(width*height / SCALE);
	menu[2].setColor(sf::Color::White);
	menu[2].setFont(Font);
	menu[2].setString("Wyjdz");
	sf::FloatRect menu2Rect = menu[2].getLocalBounds();
	menu[2].setOrigin(menu2Rect.left + menu2Rect.width / 2.0f, menu2Rect.top);
	menu[2].setPosition(sf::Vector2f(width / 2.0f, height / 1.2f));

	//Wczytanie tla menu
	sf::Texture MenuTexture;
	if (!MenuTexture.loadFromFile("Menu.jpg")) { throw std::runtime_error("Brak pliku z tlem menu"); } //zglaszanie wyjatku

	//Ustawienie tekstury tla jako sprite
	sf::Sprite MenuSprite;
	sf::Vector2f targetSize(width, height);

	MenuSprite.setScale(targetSize.x / 600,	targetSize.y / 600);
	MenuSprite.setTexture(MenuTexture);


	while (window.isOpen()) //pêtla okna
	{
		sf::Event event;

		while (window.pollEvent(event)) //pêtla zdarzeñ
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}

			//Podswietlanie pierwszego napisu
			if (sf::Mouse::getPosition(window).x >= menu[0].getPosition().x - menu[0].getGlobalBounds().width / 2.0f 
				&& sf::Mouse::getPosition(window).x <= menu[0].getPosition().x + menu[0].getGlobalBounds().width / 2.0f
				&& sf::Mouse::getPosition(window).y >= menu[0].getPosition().y
				&& sf::Mouse::getPosition(window).y <= menu[0].getPosition().y + menu[0].getGlobalBounds().height)
			{
				menu[0].setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
				{
					Play(window, GameObj, width, height); //przejœcie do gry w przypadku wyboru pierwszej opcji
				}
			}
			else
				menu[0].setColor(sf::Color::White);

			//Podswietlanie drugiego napisu
			if (sf::Mouse::getPosition(window).x >= menu[1].getPosition().x - menu[1].getGlobalBounds().width / 2.0f
				&& sf::Mouse::getPosition(window).x <= menu[1].getPosition().x + menu[1].getGlobalBounds().width / 2.0f
				&& sf::Mouse::getPosition(window).y >= menu[1].getPosition().y
				&& sf::Mouse::getPosition(window).y <= menu[1].getPosition().y + menu[1].getGlobalBounds().height)
			{
				menu[1].setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
				{
					Highscore HS(SCALE);
					HS.show_highscore(window, width, height, GameObj);//przejœcie do tablicy wyników w przypadku wyboru drugiej opcji					
				}
			}
			else
				menu[1].setColor(sf::Color::White);

			//Podswietlanie trzeciego napisu
			if (sf::Mouse::getPosition(window).x >= menu[2].getPosition().x - menu[2].getGlobalBounds().width / 2.0f 
				&& sf::Mouse::getPosition(window).x <= menu[2].getPosition().x + menu[2].getGlobalBounds().width / 2.0f
				&& sf::Mouse::getPosition(window).y >= menu[2].getPosition().y
				&& sf::Mouse::getPosition(window).y <= menu[2].getPosition().y + menu[2].getGlobalBounds().height)
			{
				menu[2].setColor(sf::Color::Red);
				if (event.type == sf::Event::MouseButtonReleased)
				{
					window.close(); //zamkniêcie gry w przypadku wyboru trzeciej opcji
				}
			}
			else
				menu[2].setColor(sf::Color::White);
		}

		window.clear();

		/////RYSOWANIE
		window.draw(MenuSprite); //Rysowanie tla menu

		for (int i = 0; i < 3; ++i)
		{
			window.draw(menu[i]); //Rysowanie napisow menu
		}		
		window.display();
	}
}

void GUI::Play(sf::RenderWindow & window, Game & GameObj, int width, int height)
{
	sf::Font Font;
	if (!Font.loadFromFile("Sans.ttf")) { throw std::runtime_error("Brak pliku z czionka"); } //zglaszanie wyjatku

	sf::Text Message;
	Message.setCharacterSize(width*height / SCALE2);
	Message.setColor(sf::Color::White);
	Message.setFont(Font);
	Message.setString("Ustaw swoje statki");
	sf::FloatRect MessageRect = Message.getLocalBounds();
	Message.setOrigin(MessageRect.left + MessageRect.width / 2.0f, MessageRect.top);
	Message.setPosition(sf::Vector2f(width / 2.0f, height / 25.0f));


	//Wczytanie tla gry
	sf::Texture GameTexture;
	if (!GameTexture.loadFromFile("Game.jpg")) { throw std::runtime_error("Brak pliku z tlem menu"); } //zglaszanie wyjatku

	//Ustawienie tekstury tla jako sprite
	sf::Sprite GameSprite;
	sf::Vector2f targetSize(width, height);

	GameSprite.setScale(targetSize.x / 800, targetSize.y / 600);
	GameSprite.setTexture(GameTexture);

	int ships_amount = number_of_ships; //liczba statkow do wstawienia

	std::vector<Coords> place_tmp_coords; //tymczasowy wektor koordynat do sprawdzania, czy nie klikamy w to samo miejsce
										  //uzywany przy ustawianiu statkow przez gracza

	std::vector<Coords> shot_tmp_coords; //strzaly gracza

	GameObj.computeraddShips(); //wylosowanie ustawienia statkow przeciwnika

	Coords HumanHitCoords;
	bool turn = true;

	//wyswietlenie ustawienia statkow przeciwnika (do testów)
	std::vector<Ship> computer_ship_vector = GameObj.get_computerShips();
	for (auto w = computer_ship_vector.begin(); w != computer_ship_vector.end(); ++w)
	{
		std::vector<Coords> s = w->get_shipCoords();
		for (auto h = s.begin(); h != s.end(); ++h)
		{
			EnemyGrid[h->get_x()][h->get_y()].setFillColor(sf::Color::Magenta);
		}
	}
	
	int k = 0;
	while (window.isOpen()) //pêtla okna
	{
		sf::Event event;
		while (window.pollEvent(event)) //pêtla zdarzeñ
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (ships_amount > 0) //pierwsza faza gry - ustawianie statków przez gracza ludzkiego
			{
				for (int i = 0; i < map_size; ++i)
				{
					for (int j = 0; j < map_size; ++j)
					{
						//warunek, czy myszka nie jest nad dana kratka
						if (sf::Mouse::getPosition(window).x >= PlayerGrid[i][j].getPosition().x
							&& sf::Mouse::getPosition(window).x <= PlayerGrid[i][j].getPosition().x + PlayerGrid[i][j].getGlobalBounds().width
							&& sf::Mouse::getPosition(window).y >= PlayerGrid[i][j].getPosition().y
							&& sf::Mouse::getPosition(window).y <= PlayerGrid[i][j].getPosition().y + PlayerGrid[i][j].getGlobalBounds().height)
						{
							PlayerGrid[i][j].setOutlineColor(sf::Color::Red);

							if (event.type == sf::Event::MouseButtonPressed) //jezeli klikniemy na kratke, to dodajemy statek do wektora
							{
								Coords temp_coords(i, j);								
								bool isAlready = false;
								for (auto e = place_tmp_coords.begin(); e != place_tmp_coords.end(); ++e)
									if (*e == temp_coords)
									{
										isAlready = true;
									}								

								if (!isAlready) //dopisanie do tymczasowego wektora statkow
								{
									PlayerGrid[i][j].setFillColor(sf::Color::Cyan);
									place_tmp_coords.push_back(temp_coords);
									std::vector<Coords> temp_coords_vector;
									temp_coords_vector.push_back(temp_coords);
									Ship temp_ship(temp_coords_vector);
									temp_ship_vector.push_back(temp_ship);
									--ships_amount;
									if (ships_amount == 0)
										PlayerGrid[i][j].setOutlineColor(sf::Color(51, 102, 153));
								}
							}
						}
						else
							PlayerGrid[i][j].setOutlineColor(sf::Color(51, 102, 153));													
					}
				}
			}
		}

		if (ships_amount == 0) //przepisanie wektora statków z GUI do logiki, przejœcie do kolejnej fazy gry
		{
			GameObj.addShips(temp_ship_vector); //dodaje wektor statkow do obiektu gracza
			Message.setString("Strzelaj!");
			MessageRect = Message.getLocalBounds();
			Message.setOrigin(MessageRect.left + MessageRect.width / 2.0f, MessageRect.top);
			Message.setPosition(sf::Vector2f(width / 2.0f, height / 25.0f));
			--ships_amount;
		}

		if (ships_amount < 0) //kolejna faza gry - strzelanie
		{
			for (int i = 0; i < map_size; ++i)
			{
				if (turn)
				{
					for (int j = 0; j < map_size; ++j)
					{
						//warunek, czy myszka nie jest nad dana kratka
						if (sf::Mouse::getPosition(window).x >= EnemyGrid[i][j].getPosition().x
							&& sf::Mouse::getPosition(window).x <= EnemyGrid[i][j].getPosition().x + EnemyGrid[i][j].getGlobalBounds().width
							&& sf::Mouse::getPosition(window).y >= EnemyGrid[i][j].getPosition().y
							&& sf::Mouse::getPosition(window).y <= EnemyGrid[i][j].getPosition().y + EnemyGrid[i][j].getGlobalBounds().height)
						{
							EnemyGrid[i][j].setOutlineColor(sf::Color::Red);

							if (event.type == sf::Event::MouseButtonPressed) //jezeli klikniemy na kratke, to zapisujemy wybrane koordynaty
							{
								HumanHitCoords = { i, j };
								
								turn = false;
								break;								
							}							
						}
						else
							EnemyGrid[i][j].setOutlineColor(sf::Color(51, 102, 153));
					}
				}				
			}			
		}
		if (!turn && event.type == sf::Event::MouseButtonReleased) //przy puszczeniu wybranej kratki wykonywany jest strza³ gracza
		{														   //ludzkiego, zaraz po nim strza³ gracza komputerowego
			bool hitExists = false;
			//sprawdzanie czy gracz nie strzela w to samo miejsce
			for (Coords x : shot_tmp_coords)
				if (x == HumanHitCoords)
					hitExists = true;

			shot_tmp_coords.push_back(HumanHitCoords);

			if (!hitExists)
			{
				GameObj.humanTurn(HumanHitCoords); //tura gracza ludzkiego
				if (GameObj.gameEnded())
				{
					End E(SCALE);
					E.show_ending_screen(window, width, height, GameObj, true); //obs³uga koñca gry
				}

				GameObj.computerTurn(); //tura gracza komputerowego
				if (GameObj.gameEnded())
				{
					End E(SCALE);
					E.show_ending_screen(window, width, height, GameObj, false); //metoda obs³uguj¹ca koniec gry	
				}
			}
			turn = true;				
		}		

		//RYSOWANIE
		window.clear(sf::Color(51, 153, 255));
		window.draw(GameSprite); //Rysowanie tla menu

		for (int i = 0; i < map_size; i++)
		for (int j = 0; j < map_size; j++)
		{
			window.draw(PlayerGrid[i][j]);
		}

		for (int i = 0; i < map_size; i++)
		for (int j = 0; j < map_size; j++)
		{
			window.draw(EnemyGrid[i][j]);
		}
		window.draw(Message);
		window.display();
	}	
}