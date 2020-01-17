#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "FileOperations.h"

class Highscore
{
private:
	sf::Text text[2]; //tablica napisów w tablicy wyników
	sf::Text winners[10]; //tablica wygranych
	float scale;

public:
	//konstruktory/destruktory
	Highscore(float x) : scale(x) {} //konstruktor inicjuj¹cy skalê
	~Highscore();

	//metody
	void Highscore::show_highscore(sf::RenderWindow & window, int width, int height, Game & GameObj); //wyœwietla tablice wyników
};

