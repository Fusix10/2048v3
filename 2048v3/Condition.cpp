#include "Condition.h";

int Condition::Victory(std::vector<std::vector<Case>> Table2048) {
	int look = 0;
	for (int i = 0; i < Table2048.size(); i++)
	{
		for (int j = 0; j < Table2048.size(); j++)
		{
			if (Table2048[i][j].Number != 0) {
				look++;
			}
			if (Table2048[i][j].Number == 2048) {
				return 2; //on a win
			}
		}
	}
	if (look == Table2048.size()*Table2048.size()) {
		for (int i = 0; i < Table2048.size(); i++)
		{
			for (int j = 0; j < Table2048.size(); j++)
			{
				int test = 0;
				test = Checkdefeat(Table2048, i , j , i - 1, j - 1);
				if (test == 1) {
					return 0;// game continue pas finie
				}
				test = Checkdefeat(Table2048, i , j , i - 1, j);
				if (test == 1) {
					return 0;// game continue pas finie
				}
				test = Checkdefeat(Table2048, i , j , i - 1, j + 1);
				if (test == 1) {
					return 0;// game continue pas finie
				}
				test = Checkdefeat(Table2048, i , j , i , j - 1);
				if (test == 1) {
					return 0;// game continue pas finie
				}
				test = Checkdefeat(Table2048, i , j , i , j + 1);
				if (test == 1) {
					return 0;// game continue pas finie
				}
				test = Checkdefeat(Table2048, i , j , i + 1, j - 1);
				if (test == 1) {
					return 0;// game continue pas finie
				}
				test = Checkdefeat(Table2048, i , j , i + 1, j + 1);
				if (test == 1) {
					return 0;// game continue pas finie
				}
				test = Checkdefeat(Table2048, i , j , i + 1, j);
				if (test == 1) {
					return 0;// game continue pas finie
				}
			}
		}
		return 1; //we lose
	}
};
int Condition::Checkdefeat(std::vector<std::vector<Case>> Table2048, int i, int j, int I, int J)
{
	if (I < 0 || I >= Table2048.size())
		return 0;

	if (J < 0 || J >= Table2048.size())
		return 0;

	if (Table2048[I][J].Number == Table2048[i][j].Number) {
		return 1;
	}
};