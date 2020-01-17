#pragma once
#include "IGameObserver.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Coords.h"
#include "Ship.h"
#include "FileOperations.h"
#include "Highscore.h"
#include <vector>

#define ITEMS 3

class GUI : public IGameObserver //publiczne dziedziczenie po interfejsie obserwatorów
{
private:
	sf::Text menu[ITEMS]; //tablica sf::Text, zawiera napisy menu pocz¹tkowego
	sf::RectangleShape PlayerGrid[5][5]; //siatka gracza ludzkiego
	sf::RectangleShape EnemyGrid[5][5]; //siatka gracza komputerowego
	std::vector<Ship> temp_ship_vector; //tymczasowy wektor statków ustawionych przez gracza ludzkiego
	int map_size;
	int number_of_ships;

public:
	//konstruktory/destruktory
	GUI(Game &, int, int, int, int); //wype³nia siatkê gracza ludzkiego i komputerowego kwadratami
	~GUI();

	//implementacja funkcji wirtualnych
	void computerScored(const Coords &);
	void computerMissed(const Coords &);
	void humanScored(const Coords &);
	void humanMissed(const Coords &);

	//metody
	void drawMenu(sf::RenderWindow &, int, int, Game &); //odpowiada za narysowanie menu glownego gry
	void Play(sf::RenderWindow &, Game &, int, int); //obs³uga rozgrywki
};