#include "Case.h";
#include "Random.h";

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

int Case::Fusion(int CaseTwoNumber) {
	if (Number == CaseTwoNumber) {
		Number += CaseTwoNumber;
		return 1;//sa a matcher
	}
	else {
		return 2;//sa ne match pas
	}
}