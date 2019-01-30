#include "window.ih"

// - Create shader handle 
// - load shader file from shaders/*
// -  set shader source
// - compile shader
// - verify compilation
// - attach Shader to program ID

void Window::addVertexShaderFromSourceFile(string &filename)
{
    //want to use booleans instead of voids so we can check success?
    bool succes = true;

    // create Shader handle
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    ifstream shaderFilestream;
    string fullName = "shaders/" + filename;
    SDL_Log("loading file %s", fullName.c_str());
    shaderFilestream.open(fullName);
    std::stringstream ss;

    ss << shaderFilestream.rdbuf();
    std::string temp = ss.str();
    SDL_Log("Vertex looks like: %s",temp.c_str());

    char *shader = temp.data();
    

    glShaderSource(vertexShader, 1, &shader, NULL);
    glCompileShader(vertexShader);

    GLint vShaderCompiled = GL_FALSE;

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vShaderCompiled);

    if (vShaderCompiled != GL_TRUE)
    {
        SDL_Log("Window::addVertexShaderFromSourceFile: unable to compile vertex shader %d\n", vertexShader);
        printShaderLog(vertexShader);
    }

    // do we do this here or somewhere else?
    glAttachShader( d_gProgramID, vertexShader);   
}