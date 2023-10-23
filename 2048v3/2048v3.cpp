// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>


std::vector<std::vector<int>> TableCreator(int lengthTable) 
{
	std::vector<std::vector<int>> Table;
	int addeur;
	for (addeur = 0; addeur < 4; addeur++)
	{
		Table[addeur] = {0,0,0,0};
	}
	return(Table);
}

int main()
{
	int i;
    std::cout << "taille du tableau: \n";
    std::cin >> i;
    TableCreator(i);
}