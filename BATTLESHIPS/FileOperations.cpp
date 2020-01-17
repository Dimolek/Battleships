#include "FileOperations.h"

FileOperations::FileOperations()
{

}
FileOperations::~FileOperations()
{

}

void FileOperations::save(const int& score, const std::string& nickname)
{
	std::ofstream file("Highscore.txt", std::ios_base::app); //otwarcie pliku z mo�liwo�ci� dopisywania
	if (!file.is_open())
	{
		throw std::runtime_error("Blad otwarcia pliku.");
	}
	const char * cstr = nickname.c_str();
	file << cstr << ": " << score << std::endl; //wrzucenie do pliku stringa z nazw� wygranego, oraz jego wyniku

	file.close(); //zamkni�cie pliku
}

std::vector<std::pair<std::string, int>> FileOperations::load()
{
	std::ifstream file("Highscore.txt", std::ios_base::in); //otwarcie pliku
	if (!file.is_open())
	{
		throw std::runtime_error("Blad otwarcia pliku.");
	}
	
	//utworzenie wektora par i string�w pomocniczych
	std::vector<std::pair<std::string, int>> highscores;
	std::string s1, s2;

	//zapisanie d�ugo�ci pliku, �eby p�tla wiedzia�a kiedy dok�adnie ma sko�czy�
	file.seekg(0, std::ios_base::end);
	int length = file.tellg();
	file.seekg(0, std::ios_base::beg);

	while (file.tellg() < length)
	{	
		getline(file, s1); //pobranie linii tekstu z pliku do stringa s1
		s2 = s1.substr(s1.find_last_of(" ") + 1); //dodanie do s2 tylko wyniku gracza
		s1 = s1.substr(0, s1.find_last_of(":")); //obci�cie stringa s1, aby zawiera� tylko nazw� gracza
		
		std::pair<std::string, int> temp = std::make_pair(s1, std::stoi(s2)); //stworzenie pary <string,int> z nazw� i wynikiem gracza
		highscores.push_back(temp); //dodanie pary do wektora zwyci�zc�w
	}
	std::sort(highscores.begin(), highscores.end(), [](std::pair<std::string, int> x,
		std::pair<std::string, int> y)->bool{return x.second < y.second; }); //posortowanie wektora

	return highscores;
}
