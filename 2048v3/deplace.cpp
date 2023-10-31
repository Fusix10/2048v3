#include "deplace.h"
#include "Condition.h"
#include <conio.h>
#include "Table.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int Utils::Move(Table* Tableau) 
{
    Condition VorD;
    int c;
    bool badKey;

    while (true)
    {
        c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            Tableau->Deplacement(2);
            Tableau->Fusion(2);
            Tableau->Deplacement(2);
            return VorD.Victory(Tableau->Table2048);
        case KEY_DOWN:
            Tableau->Deplacement(4);
            Tableau->Fusion(4);
            Tableau->Deplacement(4);
            return VorD.Victory(Tableau->Table2048);
        case KEY_RIGHT:
            Tableau->Deplacement(3);
            Tableau->Fusion(3);
            Tableau->Deplacement(3);
            return VorD.Victory(Tableau->Table2048);
        case KEY_LEFT:
            Tableau->Deplacement(1);
            Tableau->Fusion(1);
            Tableau->Deplacement(1);
            return VorD.Victory(Tableau->Table2048);
        }
    }

    return 0;
}