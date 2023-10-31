#pragma once
#include <iostream>
#include <vector>
#include "Case.h";
#include "Random.h";
#include <Windows.h>

class Table 
{
public:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::vector<Case> StorageCase;
	std::vector<std::vector<Case>> Table2048;
	Table(const std::vector<std::vector<int>>& config);
	Table(int size);
	void draw();
	void Dispatche();
	Case a;
	Random b;
	void WhiteList();
	void Deplacement(int Direction);
	void Fusion(int Direction);
};