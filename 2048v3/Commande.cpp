#include "Commande.h"
#include "Table.h"

#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77





void Commande::Mouvement() {
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
            t.Deplacement(1);
            std::cout << "gauche\n";
            break;
        default:
            badKey = true;
            break;
        }
    }
}
