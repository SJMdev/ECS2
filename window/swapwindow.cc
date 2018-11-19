#include "window.ih"

void Window::swapWindow()
{
    SDL_GL_SwapWindow(d_window);
}