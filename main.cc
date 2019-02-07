#include <entt/entt.hpp>
#include <sdl/include/SDL.h>
#include "components/position.h"
#include <stdio.h>
#include "window/window.h"
#include <cstdint>
#include <iostream>
//not necessary but useful
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) //this is necessary for SDL
{
    Window d_window;
    d_window.createWindow("Editor",
                          SDL_WINDOWPOS_UNDEFINED,  //starting xpos
                          SDL_WINDOWPOS_UNDEFINED,  //starting ypos
                          1280,
                          1024,
                          SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
                          ); 
 

    d_window.initializeSDL();
    d_window.initializeGlew(); 
    
    if (!d_window.initializeOpenGL())
    {
        SDL_Log("Unable to initialize OpenGL.");
    };

    vector<string> objectNames { {"cat.obj"} };
    
    d_window.initializeScene();
    d_window.initializeObjects(objectNames);
    d_window.initializeViewMatrices();



    // "game loop"

    SDL_Event event;
    int gameover = 0;

    while (!gameover)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    gameover = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            gameover =1;
                            break;
                    }
                    break;
            }
        }
        d_window.render();

        d_window.swapWindow();
    }



    return 0; //necessary for SDL.
}