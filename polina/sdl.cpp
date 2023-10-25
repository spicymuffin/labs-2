#include <SDL2/SDL.h>
#include <iostream>

const int WIDTH = 512;
const int HEIGHT = 512;

int main(int argc, char **argv)
{
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 10, 10);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, WIDTH / 2, HEIGHT / 2);

    return 0;
}