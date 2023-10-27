// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <time.h>
#include "Table.h"

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


void deplace() {

    Table test(1);
    bool badKey = true;
    while (badKey)
    {
        badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_LEFT:
            std::cout << "gauche\n";
            test.Deplacement(1);
            break;
        case KEY_UP:
            std::cout << "haut\n";
            test.Deplacement(2);
            break;
        case KEY_RIGHT:
            std::cout << "droite\n";
            test.Deplacement(3);
            break;
        case KEY_DOWN:
            std::cout << "bas\n";
            test.Deplacement(4);
            break;

        default:
            badKey = true;
            break;
        }
    }
}


int main()
{
	//on prepare le jeu
	srand(time(NULL));
	Table test(4);
	for (int i = 0; i < 3; i++) {
		test.Dispatche();
	}
	test.draw();
    deplace();
}
