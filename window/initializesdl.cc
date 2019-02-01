#include "window.ih"

// set major & minor openGL attributes.
// create openGL context.

void Window::initializeSDL()
{
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // OpenGL core profile - deprecated functions are disabled

    // before we start drawing, we need a context.
    // a context is a state machine that stores all data related to rendering.
    // upon application closure, the context is destroyed.
    d_gContext = SDL_GL_CreateContext(d_window);

    if (d_gContext == NULL)
    {
        SDL_Log("Window::initializeGlew: OpenGL context could not be created. SDL Error: %s\n", SDL_GetError());
        exit(1);
    }
}