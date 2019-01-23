#include "window.ih"

void Window::addVertexShaderFromSourceFile(string &filename)
{
    //open filestream
    bool succes = true;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    ifstream shaderFilestream;
    string fullName = "shaders/" + filename;
    SDL_Log("loading file %s", fullName.c_str());
    shaderFilestream.open(fullName);
    std::stringstream ss;

    ss << shaderFilestream.rdbuf();
    std::string temp = ss.str();
    SDL_Log("shader looks like: %s",temp.c_str());

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
    glAttachShader( gProgramID, vertexShader);   


    // reclaim memory?
    delete shader;
}