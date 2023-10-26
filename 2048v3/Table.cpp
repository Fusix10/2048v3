#include "Table.h";
#include "Case.h";
#include "Random.h";
#include <time.h>

Table::Table(int size)
{
	
	std::cout << "taille du tableau: \n";
	std::cout << "taille classique : 4 \n";
	std::cin >> size;
	Table2048.resize(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Table2048[i].push_back(a);
			Table2048[i][j].x = i;
			Table2048[i][j].y = j;
		}
	}
	WhiteList();
};

void Table::WhiteList() 
{
	StorageCase.clear();
	StorageCase.resize(Table2048.size() * Table2048.size());
	int w = 0;
	for (int i = 0; i < Table2048.size(); i++)
	{
		for (int j = 0; j < Table2048.size(); j++)
		{
			if (Table2048[i][j].Number == 0) {
				StorageCase[w + j] = Table2048[i][j];
			}
		}
		w += Table2048.size();
	}
}

void Table::draw()
{
	for (int i = 0; i < Table2048.size(); i++)
	{
		for (int j = 0; j < Table2048.size(); j++)
		{
			std::cout << "[" << Table2048[i][j].Number << "]";
		}
		std::cout << "\n";
	}
};

void Table::Dispatche() 
{
	int Who = b.MtdRan(StorageCase.size());
	Table2048[StorageCase[Who].x][StorageCase[Who].y].SetRandom();
	WhiteList();
}

int Table::Deplacement(int Direction) {
	/*
	*  1 = a gauche
	*  2 = en haut
	*  3 = a droite
	*  4 = en bas
	*/
	if (Direction == 1) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size(); j++) {
				if (Table2048[j][i].Number == 0) {
					continue;
				}
				else{
					if (j == 0) {
						continue;
					}
					else
					{
						if (Table2048[j - 1][i].Number != 0) {
							continue;
						}
						else {
							Table2048[j - 1][i].Number = Table2048[j][i].Number;
							Table2048[j][i].Number = 0;
						}
					}
				}
			}
		}
		
	}
	else if (Direction == 2) {


	}
	else if (Direction == 3) {


	}
	else if (Direction == 4) {


	}
}