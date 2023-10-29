#pragma once
#include "Table.h";
#include "Case.h";
#include "Random.h";
#include <time.h>;
#include <Windows.h>;
#include <iostream>
#include "Condition.h"

class deplace 
{
public:
	Condition VorD;
	deplace(Table Tableau);
	int c;
	bool badKey;
};