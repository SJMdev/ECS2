#include <entt/entt.hpp>
#include <sdl/include/SDL.h>
#include "components/position.h"
#include <stdio.h>
#include "window/window.h"
#include <cstdint>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) //this is necessary for SDL
{

    // set up  the entity registry!
    entt::registry entityRegistry;
    std::uint64_t dt = 16; //delta time?

    auto entity = entityRegistry.create();
    entityRegistry.assign<Position>(entity, 1.f, 1.f);




    //window setup!

    Window d_window;
    d_window.createWindow("Warlocks",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          640,
                          480,
                          SDL_WINDOW_OPENGL);

    // d_window.loadBMP("textures/marbles.bmp");    
    
    d_window.initializeGlew();

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

    // SDL_Surface *screen = SDL_GetWindowSurface(window);
    // SDL_BlitSurface(background, nullptr, screen, nullptr );

    // SDL_Quit();

    return 0; //necessary for SDL.
}