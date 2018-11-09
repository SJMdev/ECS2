#include "window.ih"

void Window::loadBMP(string filename)
{
    d_image = SDL_LoadBMP(filename.c_str());
    if( d_image == nullptr)
        SDL_Log("Window::loadBMP: cannot load %s ", filename.c_str());

    // actually apply the image!

    SDL_BlitSurface(d_image, nullptr, d_surface, nullptr); 
    SDL_UpdateWindowSurface(d_window);
}