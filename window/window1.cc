#include "window.ih"

Window::Window()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Window::Window: SDL_Init failed");
        exit(1);
    }
}