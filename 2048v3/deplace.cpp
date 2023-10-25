#include "deplace.h"
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

deplace::deplace() {
    bool badKey = true;
    while (badKey)
    {
        badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            std::cout << "Hello World!OPEN\n";

            break;
        case KEY_DOWN:
            break;
        case KEY_RIGHT:
            break;
        case KEY_LEFT:
            break;
        default:
            badKey = true;
            break;
        }
    }
}