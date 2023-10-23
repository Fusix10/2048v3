// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <time.h> 
#include <cstdlib>

using namespace std;

int main()
{
	int Nomber = 0;
	srand(time(nullptr));
	Nomber = rand()%4;

	std::cout << Nomber << "\n";
}
