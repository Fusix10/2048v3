// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Random.h"



int main()
{
	int Nomber;
	Random a;
	int NomberRandom = a.MtdRanTwo(6);

	std::cout << NomberRandom << "\n";
	if (NomberRandom == 1) {
		Nomber = 2;
	}
	else 
	{
		Nomber = 4;
	}
		
		

	std::cout << Nomber << "\n";
	return 0;
}
