#include "Table.h";

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
			Table2048[i].push_back(0);
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Table2048[i][j] = 0;
			std::cout << "[" << Table2048[i][j] << "]";
		}
		std::cout << "\n";
	}
};