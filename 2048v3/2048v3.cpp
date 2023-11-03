// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <time.h>
#include "Table.h"
#include <iostream>
#include <conio.h>
#include "deplace.h"
#include <SDL.h> 
#include <vector>

int SDLTest();

int main(int argc, char** args)
{
	Window* window = new Window;
	window->Create();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			window->Rectan(i, j);
		}
	} 
	//Game();
	//GameTest();
	SDLTest();
	return 0;
}

int Game() {
	//on prepare le jeu
	srand(time(NULL));
	int Gameset = 0;

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
int GameTest() {
	//on prepare le jeu
	srand(time(NULL));
	int Gameset = 0;
	std::vector< std::vector<int>> config =
	{
		{2,4,2,4},
		{4,2,4,2},
		{2,4,2,4},
		{4,2,4,2},
	};
	Table test(config);

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
};