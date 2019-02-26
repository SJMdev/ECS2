#include "window.ih"

void Window::handle_input()
{
    SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                //gameover = 1;
                break;
                //keyboard presses
                case SDL_KEYDOWN:
                {
                   switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        {
                            exit(1);
                            break;
                        }

                        default:
                            break;
                    }
                    break;
                }

                //MOUSE EVENTS
                // scrolling
                case SDL_MOUSEWHEEL:
                {
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
                // clicking the mouse!
                case SDL_MOUSEBUTTONDOWN:
                {
                   switch(event.button.button) //??? this is some magic polymorphing stuff.
                   {
                        case SDL_BUTTON_LEFT:
                        {
                            d_objects.at(0).rotationMatrix.rotateSelf(0.0f, 10.0f, 0);
                            SDL_Log("is this button clicked? %s", d_objects.at(0).rotationMatrix.toString().c_str());

                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                // moving the mouse:
                case SDL_MOUSEMOTION:
                {
                    if (event.xrel.xrel  < 0)
                        d_objects.at(0).rotationMatrix.rotateSelf(0.0f, -10.0f, 0);
                    else if (events.xrel.xrel > 0)
                        d_objects.at(0).rotationMatrix.rotateSelf(0.0f, 10.0f, 0);

                    break;
                }

                default:
                    break;          
                }
            }
        }
    
        