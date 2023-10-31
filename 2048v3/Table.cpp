#include "Table.h";
#include "Case.h";
#include "Random.h";
#include <time.h>;
#include <Windows.h>;

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

Table::Table(const std::vector<std::vector<int>>& config)
{
	Table2048.resize(config.size());
	for (int i = 0; i < config.size(); i++)
	{
		Table2048[i].resize(config.size());
		for (int j = 0; j < config.size(); j++)
		{
			Table2048[i][j].Number = config[i][j];
			Table2048[i][j].x = i;
			Table2048[i][j].y = j;
		}
	}
}

void Table::WhiteList() 
{
	StorageCase.clear();

	for (int i = 0; i < Table2048.size(); i++)
	{
		for (int j = 0; j < Table2048.size(); j++)
		{
			if (Table2048[i][j].Number == 0)
			{
				StorageCase.push_back( Table2048[i][j] );
			}
		}
	}
}

void Table::draw()
{
	for (int i = 0; i < Table2048.size(); i++)
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "[" << "i" << i << "]";
		for (int j = 0; j < Table2048.size(); j++)
		{
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << "[" << Table2048[i][j].Number << " ]";
		}
		std::cout << "\n";
		
	}
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "[" << "  " << "]";
	for (int j = 0; j < Table2048.size(); j++)
	{
		std::cout << "[" << "j" << j << "]";;
	}
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << "\n";
};

void Table::Dispatche() 
{
	WhiteList();
	if (StorageCase.size() == 0)
		return;

	int Who = b.MtdRan(StorageCase.size());
	Table2048[StorageCase[Who].x][StorageCase[Who].y].SetRandom();
}

void Table::Deplacement(int Direction) {
	/*
	*  1 = a gauche
	*  2 = en haut
	*  3 = a droite
	*  4 = en bas
	*/
	if (Direction == 1) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size(); j++) {
				if (Table2048[i][j].Number == 0) {
					for (int w = j + 1; w < Table2048.size(); w++) {
						if (Table2048[i][w].Number != 0) {
							Table2048[i][j].Number = Table2048[i][w].Number;
							Table2048[i][w].Number = 0;
							break;
						}
					}
				}
			}
		}
	}
	else if (Direction == 2) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size(); j++) {
				if (Table2048[j][i].Number == 0) {
					for (int w = j + 1; w < Table2048.size(); w++) {
						if (Table2048[w][i].Number != 0) {
							Table2048[j][i].Number = Table2048[w][i].Number;
							Table2048[w][i].Number = 0;
							break;
						}
					}
				}
			}
		}
	}
	else if (Direction == 3) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j >= 0; --j) {
				if (Table2048[i][j].Number == 0) {
					for (int w = j - 1; w >= 0; --w) {
						if (Table2048[i][w].Number != 0) {
							Table2048[i][j].Number = Table2048[i][w].Number;
							Table2048[i][w].Number = 0;
							break;
						}
					}
				}
			}
		}
	}
	else if (Direction == 4) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j >= 0; --j) {
				if (Table2048[j][i].Number == 0) {
					for (int w = j - 1; w >= 0; --w) {
						if (Table2048[w][i].Number != 0) {
							Table2048[j][i].Number = Table2048[w][i].Number;
							Table2048[w][i].Number = 0;
							break;
						}
					}
				}
			}
		}
	}
};

void Table::Fusion(int Direction) {
	if (Direction == 1) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 1; j < Table2048.size() - 1; j++) {
				if (Table2048[i][j].Number == 0)
					continue;

				if (Table2048[i][j].Number == Table2048[i][j + 1].Number) {
					Table2048[i][j].Number += Table2048[i][j + 1].Number;
					Table2048[i][j + 1].Number = 0;
				}

			}
		}
	}
	else if (Direction == 2) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size() - 1; j++) {
				if (Table2048[j][i].Number == 0)
					continue;

				if (Table2048[j][i].Number == Table2048[j + 1][i].Number) {
					if (Table2048[j][i].Number == Table2048[j + 1][i].Number) {
						Table2048[j][i].Number += Table2048[j + 1][i].Number;
						Table2048[j + 1][i].Number = 0;
					}
				}
			}
		}
	}
	else if (Direction == 3) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j > 0; --j) {
				if (Table2048[i][j].Number == 0)
					continue;

				if (Table2048[i][j].Number == Table2048[i][j - 1].Number) {
					Table2048[i][j].Number += Table2048[i][j - 1].Number;
					Table2048[i][j - 1].Number = 0;
					
				}
			}
		}
	}
	else if (Direction == 4) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j > 0; --j) {
				if (Table2048[j][i].Number == 0)
					continue;

				if (Table2048[j][i].Number == Table2048[j - 1][i].Number) {
					Table2048[j][i].Number += Table2048[j - 1][i].Number;
					Table2048[j - 1][i].Number = 0;

				}
			}
		}
	}
}