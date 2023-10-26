#include "Random.h"; 
#include <iostream>
#include <time.h>

Random::Random()
{

};

int Random::MtdRanTwo(int v) {
	srand(time(NULL));
	Pourcen = rand() % 10;
	if (Pourcen >= 0 && Pourcen <= v) {
		Number = 1;
	}
	if (Pourcen >= v && Pourcen <= 9) {
		Number = 2;
	}
	return Number;
};

int Random::MtdRan(int iMax) {
	srand(time(NULL));
	NomberRandom = rand() % iMax;

	return NomberRandom;
};