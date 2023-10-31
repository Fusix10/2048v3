#pragma once
#include <iostream>
#include <SDL.h>
#include "Table.h"

class Window
{
private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

public:
	int x = 500;
	int y = 500;
	Window();
	void Create();
	void Rectan(int t, int p);
};