#include "window.ih"

void Window::addFragmentShaderFromSourceFile(string &filename)
{
    //open filestream
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //@cleanup: maybe directly transfer to string?
    ifstream shaderFilestream;
    shaderFilestream.open("../shaders/" + filename);
    std::stringstream ss;

    // this is not preallocated.
    ss << shaderFilestream.rdbuf();
    string shaderString = ss.str();
    char *shader = shaderString.data();

    SDL_Log("fragment shader:  %s", shader);

    glShaderSource(fragmentShader, 1, &shader, NULL);

    glCompileShader(fragmentShader);

    GLint vShaderCompiled = GL_FALSE;

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &vShaderCompiled);

    if (vShaderCompiled != GL_TRUE)
    {
        SDL_Log("Window::addFragmentShaderFromSourceFile: unable to compile fragment shader %d\n", fragmentShader);
        printShaderLog(fragmentShader);
    }
    
        // do we do this here or somewhere else?
    glAttachShader( gProgramID, fragmentShader);

}