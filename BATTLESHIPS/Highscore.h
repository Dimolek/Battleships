#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "FileOperations.h"

class Highscore
{
private:
	sf::Text text[2]; //tablica napis�w w tablicy wynik�w
	sf::Text winners[10]; //tablica wygranych
	float scale;

public:
	//konstruktory/destruktory
	Highscore(float x) : scale(x) {} //konstruktor inicjuj�cy skal�
	~Highscore();

	//metody
	void Highscore::show_highscore(sf::RenderWindow & window, int width, int height, Game & GameObj); //wy�wietla tablice wynik�w
};

