#pragma once
#include <iostream>
#include <vector>
#include "Case.h";
#include "Random.h";

class Table 
{
public:
	std::vector<std::vector<Case>> Table2048;
	Table(int size);
	void draw();
	void Dispatche();
	Case a;
	Random b;
	void Start();
};