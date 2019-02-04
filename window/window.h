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
    GLuint gTBO = 0; // Texture buffer object. Should be a part of an object together with VBO VAO? or a manager?

    // this is part of the scene. Maybe make a struct or something else.
    std::vector<float> d_material; // Vec4f? 
    std::vector<float> d_lightTranslationMatrix; // this should be a Matrix!
    std::vector<float> d_lightColor; // Vec3f

    d_lightPositionLocation   = current.uniformLocation("lightPosition");
    d_lightColorLocation      = current.uniformLocation("lightColor");
    d_materialLocation        = current.uniformLocation("material");
    d_textureLocation         = current.uniformLocation("textureUniform");


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



        void addShaderFromFile(std::string &filename, GLenum shaderType, GLuint &shader);
        void initilializeScene(); // set up the lighting color, material thing, and the light rotation matrix?
        void initializeModels(std::vector<std::string> &modelNames);
        void loadModel(std::string &filename,Model &model);
        bool loadOBJFromFile(std::string &filename, Model &model);
        void setUniforms(); // set the uniforms for the current shader. We thus need to know what the active shader is.
        void fillTexture(Texture &texture, std::string &filename);
        // this is not mine
        int decodePNG(std::vector<unsigned char>& out_image,
                    unsigned long& image_width,
                    unsigned long& image_height,
                    const unsigned char* in_png,
                    size_t in_size,
                    bool convert_to_rgba32 = true);
        void loadPNG(std::vector<unsigned char>& buffer, const std::string& filename); //designed for loading files from hard disk in an std::vector
        
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