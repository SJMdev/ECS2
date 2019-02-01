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
#include "../shared/texture.h"


class Window
{
    SDL_Window  *d_window;
    SDL_Surface *d_surface;
    SDL_Surface *d_image;

    std::vector<Model> d_models;


    //openGL stuff
    GLuint d_gProgramID = 0;
    GLint  gVertexPos2DLocation = -1;
    GLuint gVBO = 0;
    GLuint gVAO = 0;
    GLuint gTBO = 0; // Texture buffer object. original character do not steal

    bool gRenderQuad = true;
    

    // SDL openGL stuff!
    SDL_GLContext d_gContext;
    
    Model d_activeModel;


    public:
        Window();
        ~Window();
        void createWindow(std::string title, int xPosition, int yPosition, int width, int height, Uint32 flags);
        void loadBMP(std::string filename);

        void initializeSDL(); // parameters?
        void initializeGlew(); // does not require parameters.
        bool initializeOpenGL(); // not sure.
        void fillTexture(Texture &texture, std::string &filename);
       

        void addShaderFromFile(std::string &filename, GLenum shaderType, GLuint &shader);

        void initializeModels(std::vector<std::string> &modelNames);
        void loadModel(std::string &filename,Model &model);
        bool loadOBJFromFile(std::string &filename, Model &model);
        void generateVertices(Model &model);

        void sendModelToBuffer(Model &model);


      


        void drawModel(Model &model);



        void calculateNormals(Model &model); //deprecated



        void addFragmentShaderFromSourceFile(std::string &filename);
        void addVertexShaderFromSourceFile(std::string &filename);

        void drawTriangle();
        

        void render();
        void swapWindow();

        void printShaderLog(GLuint shader);
        void printProgramLog(GLuint program);


    private:
        SDL_Window *windowHandle();
    
};


#endif