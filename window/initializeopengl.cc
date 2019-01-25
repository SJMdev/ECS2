#include "window.ih"


bool Window::initializeOpenGL()
{
    bool success = true;
    gProgramID = glCreateProgram();

    // addVertexShaderFromSourceFile(string("vertexshader.glsl"));
    // SDL_Log("Window::InitializeOpenGL: compiled the vertex shader!");

    addVertexShaderFromSourceFile(string("3dvertexshader.glsl"));
    SDL_Log("Window::InitializeOpenGL: compiled the vertex shader!");

    addFragmentShaderFromSourceFile(string("fragmentshader.glsl"));
    SDL_Log("Window::InitializeOpenGL: compiled the fragment shader!");

    glLinkProgram(gProgramID);
    GLint programSuccess = GL_TRUE;
    glGetProgramiv(gProgramID, GL_LINK_STATUS, &programSuccess);
    if(programSuccess != GL_TRUE)
    {
        SDL_Log("Window::InitializeOpenGL: error linking program %d\n", gProgramID);
        printProgramLog(gProgramID);
        success = false;
    }
    else
    {
        SDL_Log("linked the program!");
        loadOBJFromSourceFile(string("bunny.obj"), d_activeModel);
        // calculateNormals(d_activeModel);
        SDL_Log("amount of vertices in file: %d", d_activeModel.vertices.size());
        SDL_Log("amount of indices in file: %d", d_activeModel.indices.size());

        SDL_Log("loaded object from source file!");

        drawModel(d_activeModel);
        SDL_Log("after drawModel");
        // drawTriangle();
    }
        
    return success;
}