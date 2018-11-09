#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW
#include <sdl/include/SDL.h>
#include <string>


class Window
{
    SDL_Window *d_window;

    public:
        Window();
        ~Window();
        void createWindow(std::string title, int xPosition, int yPosition, int width, int height, Uint32 flags);

};


#endif