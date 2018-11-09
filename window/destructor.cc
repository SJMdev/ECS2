#include "window.ih"

Window::~Window()
{
  SDL_DestroyWindow(d_window);
  SDL_Quit();
}