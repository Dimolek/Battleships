#pragma once
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <algorithm>

class FileOperations
{
public:
	//konstruktory/destruktory
	FileOperations();
	~FileOperations();

	//metody
	static void save(const int&, const std::string &); //dodaje wygranego do listy zwyciêzców
	static std::vector<std::pair<std::string, int>> load(); //wczytuje listê zwyciêzców do wektora, oraz j¹ sortuje
};