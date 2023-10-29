#pragma once
#include <iostream>
#include <vector>
#include "Case.h";
#include "Random.h";
#include <Windows.h>
class Condition {
public:
	Condition();
	int Victory(std::vector<std::vector<Case>> Table2048);
	int Checkdefeat(std::vector<std::vector<Case>> Table2048, int i, int j, int I, int J);
};