// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>

#include "Table.h"

int main()
{
	//on prepare le jeu
	Table test(4);
	for (int i = 0; i < 3; i++) {
		test.Dispatche();
	}
	test.draw();

}