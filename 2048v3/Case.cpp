#include "Case.h";
#include "Random.h";
#include "Table.h";

Case::Case()
{
	Number = 0;
	x = 0;
	y = 0;
};

void Case::SetRandom() {
	Random a;
	int result = a.MtdRanTwo(6);
	if (result == 1)
	{
		Number = 2;
	}
	if (result == 2)
	{
		Number = 4;
	}
};