#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW
#include <sdl/include/SDL.h>
#include <glew/include/glew.h>
#include <sdl/include/SDL_opengl.h> 
#include <gl\glu.h>
#include <stdio.h>
#include <string>
#include "../shared/objectfilepaths.h"
#include "../shared/model.h"
#include "../shared/texture.h"
#include "../shared/object.h"
#include "../matrix/mat4.h"

class Window
{


    SDL_Window  *d_window;
    SDL_Surface *d_surface;
    SDL_Surface *d_image;
    int d_windowWidth;
    int d_windowHeight;
    std::vector<Object> d_objects;

    //openGL stuff
    GLuint d_gProgramID = 0;
    GLint  gVertexPos2DLocation = -1;
    GLuint gVBO = 0;
    GLuint gVAO = 0;
    GLuint gTBO = 0; // Texture buffer object. Should be a part of an object together with VBO VAO? or a manager?
    bool gRenderQuad = true;

    // this is part of the scene. Maybe make a struct or something else.
    std::vector<float> d_material; // Vec4f? 


    Mat4 d_lightTranslationMatrix; // this should be a Matrix!
    Mat4 d_lightRotationMatrix;
    Mat4 d_lightScaleMatrix;
    Mat4 d_lightModelMatrix;

    std::vector<float> d_lightTranslationVector; //Vec3f?
    std::vector<float> d_lightPositionVector; //Vec3f?
    std::vector<float> d_lightColor; // Vec3f
    

    //MODEL
    Mat4 d_modelMatrix;

    // VIEW
    Mat4 d_viewMatrix;
    Mat4 d_viewTranslationMatrix; // we set this after we have loaded all the objects.
    Mat4 d_viewRotationMatrix;
    Mat4 d_viewScaleMatrix;

    //PROJECTION
    Mat4 d_projectionTransformationMatrix; // we're gonna ignore this for now.
	

	// book stuff
	Mat4 d_viewPortMatrix;
	
	
	
	
    Mat4 d_projectionMatrix; // this is being set in resizeGL. call everything verbosely.



    // uniforms.
    GLint d_modelMatrixLocation = 0;
    GLint d_viewMatrixLocation = 0;
    GLint d_projectionMatrixLocation = 0; 
    GLint d_normalTransformMatrixLocation = 0;
    // ???
    GLint d_lightPositionLocation = 0;
    GLint d_lightColorLocation = 0;
    GLint d_materialLocation = 0;
    GLint d_textureLocation = 0;


    // GLuint d_objectLocation;       // If location is -1, this will make the program crash! (NICE)


    // SDL openGL stuff!
    SDL_GLContext d_gContext;
    


    public:
        Window();
        ~Window();
        void createWindow(std::string title,
					      int xPosition,
					      int yPosition,
					      int width,
					      int height,
					      Uint32 flags);


        void initializeSDL(); // parameters?
        void initializeGlew(); // does not require parameters.
        bool initializeOpenGL(); // not sure.


	
        void initializeScene(); // set up the lighting color, material thing, and the light rotation matrix?
	
        void initializeViewMatrices();
    	void initializeProjectionMatrix();
        void initializeObjects(std::vector<ObjectFilePaths> &filepaths);
        void initializeBuffers();


        void setUniforms(GLuint currentShaderProgram); // set the uniforms for the current shader. We thus need to know what the active shader is.
        void fillTexture(Texture &texture, std::string &filename);



        //this belongs in object related stuff. 
        void generateVertices(Object &object);
        void sendObjectToBuffer(Object &object);
        void sendTextureToBuffer(Object &object);

        void calculateTransformation(); //absolutely meaningless.
        void calculateViewTransformation(); // ??


	
        //openGL final steps.
        void render();
        void swapWindow();
 

        //openGL helper functions
    	//@Todo: what shader program do we attach these to?
        void addShaderFromFile(std::string &filename, GLenum shaderType, GLuint &shader);	
        void printShaderLog(GLuint shader); // helper functions
    	void printProgramLog(GLuint program);// helper functions
    	void resizeGL(int width, int height);
	
        // object helper functions
        void loadObject(std::string &filename,Object &object);
        bool loadOBJFromFile(std::string &filename, Object &object);



        //this belongs in utility, and not in window
        int decodePNG(std::vector<unsigned char>& out_image,
                    unsigned long& image_width,
                    unsigned long& image_height,
                    const unsigned char* in_png,
                    size_t in_size,
                    bool convert_to_rgba32 = true);
        void loadPNG(std::vector<unsigned char>& buffer, const std::string& filename); //designed for loading files from hard disk in an std::vector

        //deprecated & to be removed
        // void drawTriangle();

        // void drawModel(Model &model);
        // void calculateNormals(Model &model); //deprecated   
        // void addFragmentShaderFromSourceFile(std::string &filename);
        // void addVertexShaderFromSourceFile(std::string &filename);
         void loadBMP(std::string filename);

    private:
        SDL_Window *windowHandle();
    
};


#endif