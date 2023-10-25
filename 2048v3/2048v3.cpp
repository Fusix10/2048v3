// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void deplace() {
    bool badKey = true;
    while (badKey)
    {
        badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            std::cout << "haut\n";
            break;
        case KEY_DOWN:
            std::cout << "bas\n";
            break;
        case KEY_RIGHT:
            std::cout << "droit\n";
            break;
        case KEY_LEFT:
            std::cout << "gauche\n";
            break;
        default:
            badKey = true;
            break;
        }
    }
}

int main()
{
	int r = true;
	while (r) 
	{
        deplace();
	}
}
