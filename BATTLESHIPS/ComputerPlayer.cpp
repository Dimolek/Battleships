#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer()
{

}
ComputerPlayer::~ComputerPlayer()
{

}

void ComputerPlayer::computerPlaceShips(const int & map_size, const int & number_of_ships)
{
	vector<Coords> tmp_coords; //tymczasowe koordynaty, uzywane tylko do sprawdzania, czy nie zostalo wylosowane to samo
	vector<Ship> temp_ship_vector; //wektor wylosowanych statkow, przenoszony docelowo do wektora statkow w klasie
	
	while (temp_ship_vector.size() < number_of_ships)
	{
		//losowanie koordynat
		default_random_engine gen(clock());
		uniform_int_distribution<int> dist(0, (map_size - 1));
		const Coords temp_coords = { dist(gen), dist(gen) };

		bool isAlready = false; //zmienna pomocncza do sprawdzenia, czy nie zosta³y wylosowane te same koordynaty

		//sprawdzenie, czy nie zosta³y wylosowane te same koordynaty
		for (auto e = tmp_coords.begin(); e != tmp_coords.end(); ++e)
		if (*e == temp_coords)
		{
			isAlready = true;
		}

		if (!isAlready) //dopisanie do tymczasowego wektora statkow, jeœli koordynaty s¹ unikalne
		{
			tmp_coords.push_back(temp_coords);
			vector<Coords> temp_coords_vector;
			temp_coords_vector.push_back(temp_coords);
			Ship temp_ship(temp_coords_vector);
			temp_ship_vector.push_back(temp_ship);
		}
	}
	set_shipVector(temp_ship_vector);
	//ship_vector = std::move(temp_ship_vector); //przenisienie tymczasowego wektora statków do wektora statków w klasie
}

Coords ComputerPlayer::computerShot(const int & map_size)
{
	//przygotowanie generatora i rozk³adu do losowania
	default_random_engine gen(clock());
	uniform_int_distribution<int> dist(0, (map_size - 1));

	Coords temp_coords;

	//losowanie koordynat strza³u komputera ze sprawdzeniem, czy nie powielaj¹ siê
	while (shots_collection.size() < (map_size * map_size))
	{
		temp_coords = { dist(gen), dist(gen) };
		bool isAlready = false;
		for (auto e = shots_collection.begin(); e != shots_collection.end(); ++e) //sprawdza, czy nie by³o ju¿ takiego strza³u
		{
			if (*e == temp_coords)
			{
				isAlready = true;
			}
		}
		if (!isAlready)
		{
			shots_collection.push_back(temp_coords); //dodanie strza³u do kolekcji strza³ów gracza komputerowego
			return temp_coords;
		}
	}
}
