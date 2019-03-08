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

    //initialize the window.
    {
        Window d_window;
        
        int start_x_pos = 0;
        int start_y_pos = 0;

        int start_width = 1280;
        int start_height = 1024;

        Uint32 flags = 0;
        d_window.createWindow(
            "Editor",       
            start_x_pos,  
            start_y_pos,  
            start_width,
            start_height,
            flags
        ); 
    }

    // initialize the scene
    {
        Scene d_scene;
    }


    

    d_window.mainLoop();
    return 0; //necessary for SDL.
}