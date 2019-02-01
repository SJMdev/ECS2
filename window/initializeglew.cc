#include "window.ih"

void Window::initializeGlew()
{
        // SDL_Log("Window::initializeGlew");
        // initialize glew
        glewExperimental = GL_TRUE; //allow extension entry poinss to be loaded (??)
        
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK)
        {
            SDL_Log("Window::initializeGlew: ERROR INITIALIZING GLEW! %s\n", glewGetErrorString( glewError));
            exit(1);
        }

        // use VSYNC? i want to disable vsync!
        if (SDL_GL_SetSwapInterval(1) < 0)
            SDL_Log("Window::initializeGlew: Unable to set VSYNC! SDL Error: %s\n", SDL_GetError());

}