#pragma once
#include <vector>
#include "Ship.h"

class Player
{
private:
	std::vector<Ship> ship_vector; //wektor statków

public:
	//konstruktory/destruktory
	Player();
	~Player();

	//akcesory
	std::vector<Ship> get_shipVector() const {return ship_vector;}
	void set_shipVector(const std::vector<Ship> & c) {ship_vector = c;}
	std::vector<Ship>& modify_shipVector() {return ship_vector;}

	//metody
	bool isShipHit(const Coords&); //metoda sprawdza czy wektor statków zawiera podane koordynaty - jesli tak, usuwa je z wektora
};

