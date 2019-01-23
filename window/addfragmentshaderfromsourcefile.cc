#include "window.ih"

void Window::addFragmentShaderFromSourceFile(string &filename)
{
    //open filestream
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //@cleanup: maybe directly transfer to string?
    ifstream shaderFilestream;

    shaderFilestream.open("../shaders/" + filename);
    std::stringstream ss;

    ss << shaderFilestream.rdbuf();
    string shader = ss.str();

    glShaderSource(fragmentShader, 1, shader.c_str(), NULL);

    glCompileShader(fragmentShader);

    GLint vShaderCompiled = GL_FALSE;

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &vShaderCompiled);

    if (vShaderCompiled != GL_TRUE)
    {
        SDL_Log("Window::addFragmentShaderFromSourceFile: unable to compile vertex shader %d\n", vertexShader);
        printShaderLog(fragmentShader);
    }
    
        // do we do this here or somewhere else?
    glAttachShader( gProgramID, fragmentShader);


}