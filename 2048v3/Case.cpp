#include "Case.h";
#include "Random.h";

Case::Case()
{
	Nombre = 0;
};

void Case::SetRandom() {
	Random a;
	int result = a.MtdRanTwo(6);
	if (result == 1)
	{
		Nombre = 2;
	}
	if (result == 2)
	{
		Nombre = 4;
	}
};