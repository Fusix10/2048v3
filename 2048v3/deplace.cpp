#include "deplace.h"
#include <iostream>
#include <conio.h>
#include "Table.h";
#include "Condition.h";

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void Utils::Move(Table* Tableau) {

    Condition VorD;
    int c;
    bool badKey;

    badKey = true;
    while (badKey)
    {
        badKey = false;
        c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            Tableau->Deplacement(2);
            Tableau->Fusion(2);
            Tableau->Deplacement(2);
            VorD.Victory(Tableau->Table2048);
            break;
        case KEY_DOWN:
            Tableau->Deplacement(4);
            Tableau->Fusion(4);
            Tableau->Deplacement(4);
            VorD.Victory(Tableau->Table2048);
            break;
        case KEY_RIGHT:
            Tableau->Deplacement(3);
            Tableau->Fusion(3);
            Tableau->Deplacement(3);
            VorD.Victory(Tableau->Table2048);
            break;
        case KEY_LEFT:
            Tableau->Deplacement(1);
            Tableau->Fusion(1);
            Tableau->Deplacement(1);
            VorD.Victory(Tableau->Table2048);
            break;
        default:
            badKey = true;
            break;
        }
    }
}