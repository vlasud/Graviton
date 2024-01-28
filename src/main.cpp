#include <render/render.h>

#include <SDL2/SDL.h>

struct
{
    int size_x = 620;
    int size_y = 480;
    const char* title = "Shooter";

} windowSettings;

int WinMain()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        return 1;

    SDL_Window* win = SDL_CreateWindow(windowSettings.title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowSettings.size_x, windowSettings.size_y, 0);

    while (true)
    {

    }

	return 0;
}