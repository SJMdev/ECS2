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
#include "window/window.h"
#include "scene/scene.h"

using namespace std;


int main(int argc, char* argv[]) //this is necessary for SDL
{

    //initialize the window.

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


    // set up the window further (this was in mainloop before.)
        // Initialize everything.
    d_window.initializeSDL();
    d_window.initializeGlew(); 
    if (!d_window.initializeOpenGL()) {}
        //SDL_Log("Unable to initialize OpenGL.");

    else {
        //SDL_Log("initialized openGL.");
    }


    d_window.initializeBuffers(); // what does this do?

    d_window.setUniforms(d_window.d_gProgramID);

     //initializeObjects(d_objectFilePaths); // sendObjectToBuffer,sendTextureToBuffer.
    d_window.initializeScene(); // <- currently only sets materials.
    d_window.initializeViewMatrices();
    d_window.initializeProjectionMatrix();  


// initialize the scene
    Scene d_scene; //also invokes initializelights.

    ObjectFilePaths cat1
    {
        "cat.obj", 
        "cat_norm_rot_flipped.png"
    };
    
    ObjectFilePaths cat2
    {
        "cat.obj", 
        "cat_diff_rot_flipped.png"
    };
    
    vector<ObjectFilePaths> d_objectFilePaths;
    
//	d_objectFilePaths.push_back(cat1);
    d_objectFilePaths.push_back(cat2);

    d_scene.initializeObjects(d_objectFilePaths);


    // add objects to the scene

    for (auto &object: d_scene.d_objects)
    {
        d_window.sendObjectToBuffer(object);
        d_window.sendTextureToBuffer(object);
    }



    int gameover = 0;
    while (!gameover)
    {
        d_window.handle_input();
        
        // simulate(dt);
        //d_window.render();
        d_window.prepareToRender();
        for (auto &object : d_scene.d_objects)
            d_window.drawObject(object);

        d_window.render(); // <- for gl_useprogram(0)

        d_window.swapWindow();
    }
    //d_window.mainLoop();
    return 0; //necessary for SDL.
}