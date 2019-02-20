#include "window.ih"

void Window::mainLoop()
{
    
    // Initialize everything.
    initializeSDL();
    initializeGlew(); 
    if (!d_window.initializeOpenGL())
        SDL_Log("Unable to initialize OpenGL.");
    d_window.initializeBuffers();
    

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
	vector<ObjectFilePaths> d_objects;
	d_objects.push_back(cat1);
    d_objects.push_back(cat2);
    d_window.initializeScene();
    d_window.initializeObjects(d_objects); // sendObjectToBuffer,sendTextureToBuffer.
    d_window.initializeViewMatrices();
    d_window.initializeProjectionMatrix();    
    
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

    while(true)
    {

    }

}