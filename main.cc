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

#include "shared/objectfilepaths.h"

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
    
     d_window.mainLoop();
    
  
    
    return 0; //necessary for SDL.
}