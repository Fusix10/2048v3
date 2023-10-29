#include "deplace.h"

#include "deplace.h"
#include <iostream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

deplace::deplace() {
    badKey = true;
    while (badKey)
    {
        badKey = false;
        c = 0;
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