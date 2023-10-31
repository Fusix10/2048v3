#include "Window.h"
#include <SDL.h>

using namespace std;

Window::Window() {
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
};

void Window::Create() {
	window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		x, y, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}


void Window::Rectan(int h, int p) {
	SDL_Color blanc = { 255, 255, 255, 255 };
	SDL_SetRenderDrawColor(renderer, blanc.r, blanc.g, blanc.b, blanc.a);
	SDL_Rect rect = { h, p, x / 4, y / 4 };
	SDL_RenderDrawRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}