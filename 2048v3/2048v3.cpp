// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <time.h>
#include "Table.h"
#include <iostream>
#include <conio.h>
#include "deplace.h"
#include "Window.h"

int main(int argc, char** argv)
{
	Window* window = new Window;
	window->Create();
	window->Rectan(0, 0);

	//on prepare le jeu
	srand(time(NULL));
	Table test(4);
	for (int i = 0; i < 6; i++) {
		test.Dispatche();
	}
	test.Table2048[0][0].Number = 4;
	test.Table2048[0][1].Number = 2;
	test.Table2048[0][2].Number = 2;
	test.Table2048[0][3].Number = 2;
	test.draw();
	while (true)
	{
		Utils::Move(&test);
		test.draw();
	}
}

