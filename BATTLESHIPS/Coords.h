#pragma once
class Coords
{
private:
	int x, y; //sk³adowe koordynat

public:
	//konstruktory/destruktory
	Coords(int x1 = 0, int y1 = 0) : x(x1), y(y1) {} //wstêpna inicjalizacja zerami, ewentualnie przekazanymi wartoœciami
	~Coords();

	//akcesory
	int get_x() const {return x;} //zwraca pierwsz¹ sk³adow¹ koordynat
	int get_y() const {return y;} //zwraca drug¹ sk³adow¹ koordynat

	//przeci¹¿one operatory
	bool operator==(const Coords &);
};