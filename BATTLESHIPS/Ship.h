#pragma once
#include <vector>
#include "Coords.h"
class Ship
{
private:
	int ship_length; //wielkosc statku(dlugosc wektora koordynat), dekrementowany przy zatopieniu statku
	std::vector<Coords> ship_coords; //wektor koordynat

public:
	//konstruktory/destruktory
	Ship();
	Ship(const std::vector<Coords> &); //konstruktor, inicjuje zmienne klasy wektorem koordynat
	~Ship();

	//akcesory
	int get_length() const {return ship_length;} //akcesor wielkosci statku
	std::vector<Coords> get_shipCoords() const {return ship_coords;} //akcesor wektora statkow

	//metody
	bool isHit (const Coords &); //pornowuje podane koordynaty z koordynatami statku	
};