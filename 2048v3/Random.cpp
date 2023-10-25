#include "Random.h"; 

#include <iostream>
#include <time.h>

Random::Random()
{
	



};

int Random::MtdRanTwo(int v) {
	
	Pourcen = rand() % 10;
	if (Pourcen >= 0 && Pourcen <= v) {
		Nomber = 1;
	}
	if (Pourcen >= v && Pourcen <= 9) {
		Nomber = 2;
	}
	return Nomber;
};


