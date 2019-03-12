#include "window.ih"


void Window::handle_input()
{
    SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(1);
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
                // case SDL_MOUSEWHEEL:
                // {
                //     if (event.wheel.y > 0)
                //     {
                //         for (auto &object :d_objects)
                //         {
                //             object.scaleMatrix.scaleSelf(1.1f);
                //             SDL_Log("scaleMatrix: %s", object.scaleMatrix.toString().c_str());
                //         }
                //     }
                //     else if (event.wheel.y < 0)
                //     {
                //         for (auto &object : d_objects)
                //             object.scaleMatrix.scaleSelf(0.9f);
                //     }
                //     break;
                // }
                // // clicking the mouse!
                // case SDL_MOUSEBUTTONDOWN:
                // {
                //    switch(event.button.button) //??? this is some magic polymorphing stuff.
                //    {
                //         case SDL_BUTTON_LEFT:
                //         {
                //             // d_objects.at(0).rotationMatrix.rotateSelf(0.0f, 10.0f, 0);
                //             //SDL_Log("clicked left Mouse button.");
                //             d_left_mouse_clicked = true;
                //             break;
                //         }
                //         default:
                //             break;
                //     }
                //     break;
                // }
                // case SDL_MOUSEBUTTONUP:
                //     switch(event.button.button)
                //     {
                //         case SDL_BUTTON_LEFT:
                //         {
                //             SDL_Log("released left Mouse button.");
                //             //release
                //             d_left_mouse_clicked = false;
                //             break;
                //         }
                //     }
                // // moving the mouse:
                // case SDL_MOUSEMOTION:
                // {
                //   if (d_left_mouse_clicked)
                //   {
                    
                //     if (event.motion.xrel  < 0)
                //         d_objects.at(0).rotationMatrix.rotateSelf(0.0f, -1.0f, 0);
                //     else if (event.motion.xrel > 0)
                //         d_objects.at(0).rotationMatrix.rotateSelf(0.0f, 1.0f, 0);

                //     if (event.motion.yrel < 0)
                //         d_objects.at(0).rotationMatrix.rotateSelf(-1.0f, 0.0f, 0);
                //     else if (event.motion.yrel > 0)
                //         d_objects.at(0).rotationMatrix.rotateSelf(1.0f, 0.0f, 0.0f);
                //   }
                //     break;
                
                // }

                default:
                    break;          
                }
            }
        }
    
        