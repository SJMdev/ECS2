#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW
#include <sdl/include/SDL.h>
#include <glew/include/glew.h>
#include <sdl/include/SDL_opengl.h> 
#include <gl\glu.h>
#include <stdio.h>
#include <string>
#include "../shared/vecf.h"
#include "../shared/model.h"


class Window
{
    SDL_Window  *d_window;
    SDL_Surface *d_surface;
    SDL_Surface *d_image;

    //openGL stuff
    GLuint gProgramID = 0;
    GLint  gVertexPos2DLocation = -1;
    GLuint gVBO = 0;
    GLuint gVAO = 0;
    //GLuint gIBO = 0;
    GLuint gIBO = 0;

    bool gRenderQuad = true;
    

    // SDL openGL stuff!
    SDL_GLContext d_gContext;
    
    Model d_activeModel;


    public:
        Window();
        ~Window();
        void createWindow(std::string title, int xPosition, int yPosition, int width, int height, Uint32 flags);
        void loadBMP(std::string filename);
        void initializeGlew();
        bool initializeOpenGL();

        void printShaderLog(GLuint shader);
        void printProgramLog(GLuint program);



        // stuff for initialize openGL.
        bool loadOBJFromSourceFile(std::string &filename, Model &model);
        void calculateNormals(Model &model);
        

        void addFragmentShaderFromSourceFile(std::string &filename);
        void addVertexShaderFromSourceFile(std::string &filename);
        void drawTriangle();
        void drawModel(Model &model);

        void render();
        void swapWindow();

        


        SDL_Window *windowHandle();
    
};


#endif