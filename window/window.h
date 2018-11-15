#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW
#include <sdl/include/SDL.h>
#include <glew/include/glew.h>
#include <sdl/include/SDL_opengl.h> 
#include <gl\glu.h>
#include <stdio.h>
#include <string>


class Window
{
    SDL_Window *d_window;
    SDL_Surface *d_surface;
    SDL_Surface *d_image;

    //openGL stuff
    GLuint gProgramID = 0;
    GLint gVertexPos2DLocation = -1;
    GLuint gVBO = 0;
    GLuint gIBO = 0;
    bool gRenderQuad = true;
    

    //  // SDL openGL stuff!
    SDL_GLContext d_gContext;
    //

    public:
        Window();
        ~Window();
        void createWindow(std::string title, int xPosition, int yPosition, int width, int height, Uint32 flags);
        void loadBMP(std::string filename);
        void initializeGlew();
        bool initializeOpenGL();

        void printShaderLog(GLuint shader);
        void printProgramLog(GLuint program);

        void render();

    
};


#endif