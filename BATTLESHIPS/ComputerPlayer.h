#pragma once
#include "Player.h"
#include "Coords.h"
#include "Ship.h"
#include <random>
#include <ctime> 
#include <cstdlib>
#include <list>

class ComputerPlayer : public Player
{
private:
	std::vector<Coords> shots_collection; //wektor oddanych strzalow gracza komputerowego

public:
	//konstruktor/destruktory
	ComputerPlayer();
	~ComputerPlayer();

	//metody
	void computerPlaceShips(const int &, const int &); //wypelnia wektor statkow gracza komputerowego
	Coords computerShot(const int &); //zwraca strzal gracza komputerowego
};
