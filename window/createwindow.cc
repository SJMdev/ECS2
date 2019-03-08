#include "window.ih"

void Window::createWindow(string title, int xPosition, int yPosition, int width, int height, Uint32 flags)
{
    // #if SDL
    {
        xPosition =  SDL_WINDOWPOS_UNDEFINED;
        yPosition =  SDL_WINDOWPOS_UNDEFINED,  
        flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;


        d_window = SDL_CreateWindow(title.c_str(),
                                    xPosition,
                                    yPosition,
                                    width,
                                    height,
                                    flags);
        if (d_window == nullptr)
        {
            SDL_Log("Window::CreateWindow: window could not be created!");
            exit(1);
        }
        d_surface = SDL_GetWindowSurface(d_window);
    }

    d_width = width;
    d_height = height;
	float fwidth  = static_cast<float>(d_width);
	float fheight = static_cast<float>(d_height);

	
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

}