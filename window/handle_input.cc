#include "window.ih"

void Window::handle_input()
{
    SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                gameover = 1;
                break;
                case SDL_KEYDOWN:
                {
                   switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        {
                             gameover =1;
                              break;
                        }
                        case SDLK_PLUS:
                        {
                            d_objects.at(0).scaleMatrix.scaleSelf(1.01f);   
                            SDL_Log("scaleMatrix: %s", d_objects.at(0).scaleMatrix.toString().c_str());
                        }
                    }
                    break;
                } 
                case SDL_MOUSEWHEEL:
                {
                    // this is a good question. What happens when / if we zoom? do we scale everything else? or does the viewmatrix need a scale?
                    
                    if (event.wheel.y > 0)
                    {
                        for (auto &object :d_objects)
                        {
                            object.scaleMatrix.scaleSelf(1.1f);
                            SDL_Log("scaleMatrix: %s", object.scaleMatrix.toString().c_str());
                        }
                    }
                    else if (event.wheel.y < 0)
                    {
                        for (auto &object : d_objects)
                            object.scaleMatrix.scaleSelf(0.9f);
                    }
                    break;
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                    if (event.button == SDL_BUTTON_LEFT)
                    {
                        d_objects.at(0).rotationMatrix.rotateSelf(0.0f,15.0f, 0);    
                    }
                    
                    break;                                      
                }
                default:
                    break;
                
                        
            }
        }
    
}