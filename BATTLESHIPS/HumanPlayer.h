#pragma once
#include "Player.h"
#include "Ship.h"
#include "Coords.h"
#include <algorithm>

class HumanPlayer : public Player
{
private:
	int score; //wynik

public:
	//konstruktory/destruktory
	HumanPlayer() : score(0){}
	~HumanPlayer();

	//akcesory
	int get_score() const {return score;} //zwraca wynik
	int& modify_score() {return score;} //pozwala na modyfikowanie wyniku
};