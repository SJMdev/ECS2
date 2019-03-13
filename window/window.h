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
#include "../light/light.h"

#include "../scene/scene.h"

#include <unordered_map>

class Window
{
    // Window properties.
    SDL_Window  *d_window;
    SDL_Surface *d_surface;
    SDL_Surface *d_image;
    int d_width;
    int d_height;    
    // SDL openGL stuff!
    SDL_GLContext d_gContext;

    // openGL stuff
    // GLuint d_gProgramID = 0; is now public!
    GLint  gVertexPos2DLocation = -1;
    GLuint gVBO = 0;
    GLuint gVAO = 0;

    //scene?
    std::vector<Object> d_objects;
    std::vector<float> d_material; // Vec4f? 
    std::vector<float> d_lightPositionVector; //Vec3f?
    std::vector<float> d_lightColor; // Vec3f
    std::vector<float> d_lightTranslationVector; //Vec3f?
 
    // LIGHT!
    Light d_light; // d_lightful!

    // input handling.
    bool d_left_mouse_clicked = false; 


    //MODEL
    Mat4 d_modelMatrix;
    
    // VIEW
    Mat4 d_viewMatrix;
    Mat4 d_viewTranslationMatrix; // we set this after we have loaded all the objects.
    Mat4 d_viewRotationMatrix;
    Mat4 d_viewScaleMatrix;

    //PROJECTION
    Mat4 d_projectionTransformationMatrix;
    Mat4 d_projectionMatrix; // this is being set in resizeGL. call everything verbosely.

    // uniforms (refactor to map?).


    GLint d_modelMatrixLocation = 0;
    GLint d_viewMatrixLocation = 0;
    GLint d_projectionMatrixLocation = 0; 
    GLint d_normalTransformMatrixLocation = 0;
    GLint d_lightPositionLocation = 0;
    GLint d_lightColorLocation = 0;
    GLint d_materialLocation = 0;
    GLint d_textureLocation = 0;

    std::unordered_map<std::string, GLuint> d_uniforms;
    // GLuint d_objectLocation;       // If location is -1, this will make the program crash! (NICE)
    
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
        void initializeBuffers();
        
        void setUniforms(GLuint currentShaderProgram); // set the uniforms for the current shader. We thus need to know what the active shader is.
        void sendObjectToBuffer(Object &object);
        void sendTextureToBuffer(Object &object);
        void calculateViewTransformation(); // ??
        void handleInput(Scene &scene); // we handle
        //openGL final steps.
        void drawObject(Object &object);
        void prepareToRender();
        void render();
        void swapWindow();

        //openGL helper functions
    	//@Todo: what shader program do we attach these to?
        void addShaderFromFile(std::string &filename, GLenum shaderType, GLuint &shader);	
        void printShaderLog(GLuint shader); // helper functions
    	void printProgramLog(GLuint program);// helper functions
    	void resizeGL(int width, int height);
	
        GLuint d_gProgramID = 0;
    private:
        SDL_Window *windowHandle();
    
};


#endif