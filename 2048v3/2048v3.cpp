// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <time.h>
#include "Table.h"
#include <iostream>
#include <conio.h>
#include "deplace.h"

int main()
{
	//on prepare le jeu
	srand(time(NULL));
	Table test(4);
	for (int i = 0; i < 3; i++) {
		test.Dispatche();
	}
	//test.Table2048[3][2].Number = 2048;
	test.draw();
	while (true)
	{
		deplace Moves(test);
		test.draw();
	}
	
}
