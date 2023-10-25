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
		for (int i = 0; i < size; i++)
		{
			Table2048[i].push_back(a);
		}
	}
};

void Table::Start() 
{
	for (int i = 0; i < 3; i++) {
		Table2048[b.MtdRan(Table2048.size())][b.MtdRan(Table2048.size())].SetRandom();
	}
};

void Table::draw()
{
	for (int i = 0; i < Table2048.size(); i++)
	{
		for (int j = 0; j < Table2048.size(); j++)
		{
			Table2048[i][j].Nombre = 0;
			std::cout << "[" << Table2048[i][j].Nombre << "]";
		}
		std::cout << "\n";
	}
};

void Table::Dispatche() 
{

}
