#include "window.ih"


bool Window::initializeOpenGL()
{
    bool success = true;


    d_gProgramID = glCreateProgram();
    
    addVertexShaderFromSourceFile(string("3dvertexshader.glsl"));
    SDL_Log("Window::InitializeOpenGL: compiled the vertex shader.");

    addFragmentShaderFromSourceFile(string("fragmentshader.glsl"));
    SDL_Log("Window::InitializeOpenGL: compiled the fragment shader.");

    glLinkProgram(d_gProgramID);


    GLint programSuccess = GL_TRUE;


    glGetProgramiv(d_gProgramID, GL_LINK_STATUS, &programSuccess);
    if(programSuccess != GL_TRUE)
    {
        SDL_Log("Window::InitializeOpenGL: error linking program %d\n", d_gProgramID);
        printProgramLog(d_gProgramID);
        success = false;
    }
    else
    {
        SDL_Log("Successfully linked the program.");
        loadOBJFromSourceFile(string("cat.obj"), d_activeModel);
        SDL_Log("Successfully loaded object from source file.");
        SDL_Log("amount of vertices in file: %d", d_activeModel.vertices.size());
        SDL_Log("amount of vertex indices in file: %d", d_activeModel.vertex_indices.size());
        SDL_Log("amount of normal indices in file: %d", d_activeModel.normal_indices.size());

        SDL_Log("Successfully loaded object from source file.");

        // clear before "drawing".
        glClearColor(0.2f, 0.5f, 0.7f, 0.0f); // r, g, b, a
        drawModel(d_activeModel);

        // SDL_Log("after drawModel");
    }
        
    return success;
}