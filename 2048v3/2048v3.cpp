// 2048v3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <time.h>
#include "Table.h"
#include <iostream>
#include <conio.h>
#include "deplace.h"

#include <vector>
#include "Window.h"

int main(int argc, char** argv)
{
	Window* window = new Window;
	window->Create();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			window->Rectan(i, j);
		}
	} 


	//on prepare le jeu
	srand(time(NULL));
	int Gameset = 0;
	/*std::vector< std::vector<int>> config =
	{
		{2,4,2,4},
		{4,2,4,2},
		{2,4,2,4},
		{4,2,4,2},
	};*/
	
	//Table test(config);

	Table test(4);
	
	for (int i = 0; i < 3; i++) {
		test.Dispatche();
	}
	test.draw();

	while (true)
	{
		
		Gameset = Utils::Move(&test);
		
		if (Gameset == 1) {
			std::cout << "YOU LOSE \n";
			return 0;
		}
		else if (Gameset == 2) {
			std::cout << "you... you... YOU WIIINNN ?????!!!!!! \n";
			return 0;
		}
		test.Dispatche();
		test.draw();
		
	}
	return 0;
}

int SDLTest() {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Surface* ImgSurface = SDL_LoadBMP("Cube.bmp");
	if (!ImgSurface) {
		std::cout << "rien" << SDL_GetError <<"\n";
		exit(1);
	}
	SDL_Event windowEvent;


	SDL_Rect Pos;
	Pos.x = 0;
	Pos.y = 0;

	int iError = SDL_Init(SDL_INIT_VIDEO);
	if (iError != 0)
	{
		std::cout << "Error SDL_Init :" << SDL_GetError();
		exit(1);
	}
	SDL_CreateWindowAndRenderer(640 * 2, 480 * 2, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, 2, 2);

	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(renderer, 640/2, 480/2);

	SDL_RenderPresent(renderer);

	SDL_Texture* ImgTexture = SDL_CreateTextureFromSurface(renderer, ImgSurface);
	if (ImgTexture == NULL)
	{
		std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
		exit(1);
	}



	while (true) {
		if (SDL_PollEvent(&windowEvent)) {
			if (SDL_QUIT == windowEvent.type) {
				break;
			}
		}
		SDL_BlitSurface(ImgSurface,NULL, ImgSurface,NULL);

		SDL_QueryTexture(ImgTexture, NULL, NULL, &Pos.w, &Pos.h);
		SDL_RenderCopy(renderer, ImgTexture, NULL, &Pos);
		SDL_UpdateWindowSurface(window);
	}

	SDL_FreeSurface(ImgSurface);
	SDL_DestroyTexture(ImgTexture);

	ImgSurface = NULL;

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0; 
}
