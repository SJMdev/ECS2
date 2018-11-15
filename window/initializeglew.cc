#include "window.ih"

void Window::initializeGlew()
{
    d_gContext = SDL_GL_CreateContext(d_window);
    if (d_gContext == nullptr)
    {
        SDL_Log("Window::initializeGlew: OpenGL context could not be created. SDL Error: %s\n", SDL_GetError());
        exit(1);
    }
    else
    {
        // SDL_Log("Window::initializeGlew");
        // initialize glew
        glewExperimental = GL_TRUE;
        GLenum glewError = glewInit();
        if (glewError != GLEW_OK)
        {
            SDL_Log("Window::initializeGlew: ERROR INITIALIZING GLEW! %s\n", glewGetErrorString( glewError));
        }
        // use VSYNC?
        if (SDL_GL_SetSwapInterval(1) < 0)
            SDL_Log("Window::initializeGlew: Unable to set VSYNC! SDL Error: %s\n", SDL_GetError());
        
        //initialize openGL
        if (!initializeOpenGL())
        {
            SDL_Log("Window::initializeGlew: Unable to initialize OpenGL.\n");
        }
    }
}