#include "window.ih"

void Window::createWindow(string title, int xPosition, int yPosition, int width, int height, Uint32 flags)
{
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
    d_windowWidth = width;
    d_windowHeight = height;
	
	float fwidth  = static_cast<float>(d_windowWidth);
	float fheight = static_cast<float>(d_windowHeight);
	
//	d_viewPortMatrix = {fwidth / 2.0f, 0, 0, (fwidth -1.0f) / 2.0f,
	                //0, fheight / 2.0f, 0 , (fheight -1.0f) / 2.0f,
		                //0, 0, 1, 0,
		                //0, 0, 0, 1};
	
    // initialize openGL
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

}