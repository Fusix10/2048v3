// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <time.h>
#include "Table.h"
#include <iostream>
#include <conio.h>
#include "deplace.h"

#include <vector>
#include "Window.h"

int main(int argc, char** argv)
{
	Window* window = new Window;
	window->Create();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			window->Rectan(i, j);
		}
	} 


	//on prepare le jeu
	srand(time(NULL));
	int Gameset = 0;
	/*std::vector< std::vector<int>> config =
	{
		{2,4,2,4},
		{4,2,4,2},
		{2,4,2,4},
		{4,2,4,2},
	};*/
	
	//Table test(config);

	Table test(4);
	
	for (int i = 0; i < 3; i++) {
		test.Dispatche();
	}
	test.draw();

	while (true)
	{
		
		Gameset = Utils::Move(&test);
		
		if (Gameset == 1) {
			std::cout << "YOU LOSE \n";
			return 0;
		}
		else if (Gameset == 2) {
			std::cout << "you... you... YOU WIIINNN ?????!!!!!! \n";
			return 0;
		}
		test.Dispatche();
		test.draw();
		
	}
	return 0;
}
