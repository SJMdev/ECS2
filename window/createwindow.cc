#include "window.ih"

void Window::createWindow(string title, int xPosition, int yPosition, int width, int height, Uint32 flags)
{
    d_window = SDL_CreateWindow(title.c_str(),
                                xPosition,
                                yPosition,
                                width,
                                height,
                                flags);
}