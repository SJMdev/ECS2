#include "window.ih"

void Window::addVertexShaderFromSourceFile(string &filename)
{
    //open filestream
    bool succes = true;
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    ifstream shaderFilestream;

    shaderFilestream.open("../shaders/" + filename);
    std::stringStream shader;

    shader << shaderFilestream;

    glShaderSource(vertexShader, 1, shader.str(), NULL);

    glCompileShader(vertexShader);

    GLint vShaderCompiled = GL_FALSE;

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vShaderCompiled);

    if (vShaderCompiled != GL_TRUE)
    {
        SDL_Log("Window::addVertexShaderFromSourceFile: unable to compile vertex shader %d\n", vertexShader);
        printShaderLog(vertexShader);
    }

    // do we do this here or somewhere else?
    glAttachShader( gProgramID, vertexShader);   
}