#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
class End
{
private:
	float scale;

public:
	//konstruktory/destruktory
	End(float x) : scale(x) {}
	~End();

	//metody
	void End::show_ending_screen(sf::RenderWindow &, int, int, Game &, bool); //rysowanie ekranu koncowego
};

