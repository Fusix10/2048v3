#pragma once
#include <iostream>
#include <vector>
#include "Case.h";
#include "Random.h";

class Table
{
public:
	std::vector<Case> StorageCase;
	std::vector<std::vector<Case>> Table2048;
	Table(int size);
	void draw();
	void Dispatche();
	Case a;
	Random b;
	void WhiteList();
	int Deplacement(int Direction);
};