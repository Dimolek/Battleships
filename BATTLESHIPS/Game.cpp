#include "Game.h"


Game::~Game()
{

}

bool Game::registerObserver(IGameObserver* obs)
{
	for (int i = 0; i < observer_vector.size(); ++i)
	{
		if (obs == observer_vector[i])
		{
			return false;
		}
	}
	this->observer_vector.push_back(obs);

	return true;
}

void Game::addShips(std::vector<Ship> ship_vector)
{
	h_player.set_shipVector(ship_vector);
}

void Game::computeraddShips()
{
	c_player.computerPlaceShips(get_size(), get_shipsAmount());
}

void Game::computerTurn()
{
	Coords temp_coords = c_player.computerShot(get_size()); //wylosowanie strza�u komputera
	if (h_player.isShipHit(temp_coords)) //je�eli komputer trafi�, to statek jest usuwany z wektora
	{																   //statk�w gracza ludzkiego, oraz powiadamiamy obserwator�w
		for (int i = 0; i < observer_vector.size(); ++i)
		{
			observer_vector[i]->computerScored(temp_coords);
		}
	}
	else //je�eli komputer nie trafi�, to wywo�ujemy odpowiedni� metod� obserwator�w
	{
		for (int i = 0; i < observer_vector.size(); ++i)
		{
			observer_vector[i]->computerMissed(temp_coords);
		}
	}
}

void Game::humanTurn(const Coords & c)
{
	if (c_player.isShipHit(c))
	{
		for (int i = 0; i < observer_vector.size(); ++i)
		{
			observer_vector[i]->humanScored(c);
		}

	}
	else //je�eli nie trafili�my, to wywo�ujemy odpowiedni� metod� obserwator�w
	{
		for (int i = 0; i < observer_vector.size(); ++i)
		{
			observer_vector[i]->humanMissed(c);
		}
	}
	++h_player.modify_score(); //dodanie strza�u do liczby oddanych strza��w przez gracza ludzkiego
}

bool Game::gameEnded()
{
	return c_player.get_shipVector().size() == 0 || h_player.get_shipVector().size() == 0;
}