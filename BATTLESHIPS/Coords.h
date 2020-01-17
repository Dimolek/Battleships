#pragma once
class Coords
{
private:
	int x, y; //sk�adowe koordynat

public:
	//konstruktory/destruktory
	Coords(int x1 = 0, int y1 = 0) : x(x1), y(y1) {} //wst�pna inicjalizacja zerami, ewentualnie przekazanymi warto�ciami
	~Coords();

	//akcesory
	int get_x() const {return x;} //zwraca pierwsz� sk�adow� koordynat
	int get_y() const {return y;} //zwraca drug� sk�adow� koordynat

	//przeci��one operatory
	bool operator==(const Coords &);
};