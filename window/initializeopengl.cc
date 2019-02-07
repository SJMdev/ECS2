#include "window.ih"

// create openGL program
// attach some shaders? or do shaders belong to objects?
// do we need to keep track of the shaders?

bool Window::initializeOpenGL()
{
    bool success = true;
    d_gProgramID = glCreateProgram();

    glEnable(GL_DEPTH_TEST);
    GLuint vertexShader;
    GLuint fragmentShader;
    //addShaderFromFile(string("3dvertexshader.glsl"), GL_VERTEX_SHADER, vertexShader);
    //addShaderFromFile(string("fragmentshader.glsl"), GL_FRAGMENT_SHADER, fragmentShader);
    addShaderFromFile(string("gouraud_vertexshader.glsl"), GL_VERTEX_SHADER, vertexShader);
    addShaderFromFile(string("gouraud_fragmentshader.glsl"), GL_FRAGMENT_SHADER, fragmentShader);
    //addShaderFromFile(string("normal_vertexshader.glsl"), GL_VERTEX_SHADER, vertexShader);
    //addShaderFromFile(string("normal_fragmentshader.glsl"),GL_FRAGMENT_SHADER, fragmentShader);
    glAttachShader(d_gProgramID, vertexShader);
    glAttachShader(d_gProgramID, fragmentShader);

    glLinkProgram(d_gProgramID);

    //check for success 
    GLint programSuccess = GL_TRUE;
    glGetProgramiv(d_gProgramID, GL_LINK_STATUS, &programSuccess);
    if (programSuccess != GL_TRUE)
    {       
        SDL_Log("Window::InitializeOpenGL: error linking program %d\n", d_gProgramID);
        printProgramLog(d_gProgramID);
        success = false;
    }
      
    return success;
}