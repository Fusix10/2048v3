#include "Commande.h"

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
        case KEY_LEFT:
            t.Deplacement(1);
            break;
        case KEY_UP:
            t.Deplacement(2);
            break;
        case KEY_RIGHT:
            t.Deplacement(3);
            break;
        case KEY_DOWN:
            t.Deplacement(4);
            break;
        
        default:
            badKey = true;
            break;
        }
    }
}
