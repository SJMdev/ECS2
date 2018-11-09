#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW
#include <sdl/include/SDL.h>
#include <string>


class Window
{
    SDL_Window *d_window;
    SDL_Surface *d_surface;
    SDL_Surface *d_image;

    public:
        Window();
        ~Window();
        void createWindow(std::string title, int xPosition, int yPosition, int width, int height, Uint32 flags);

        void loadBMP(std::string filename);
    
};


#endif