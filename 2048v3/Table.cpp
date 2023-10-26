#include "Table.h";
#include "Case.h";
#include "Random.h";

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
			Table2048[i][j].Number = 0;
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
