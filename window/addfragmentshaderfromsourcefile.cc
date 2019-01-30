#include "window.ih"

void Window::addFragmentShaderFromSourceFile(string &filename)
{
    //create Shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //@cleanup: maybe directly transfer to string?
     ifstream shaderFilestream;
    string fullName = "shaders/" + filename;
    SDL_Log("loading file %s", fullName.c_str());
    shaderFilestream.open(fullName);
    std::stringstream ss;

    ss << shaderFilestream.rdbuf();
    std::string temp = ss.str();
    SDL_Log("Fragment shader: %s",temp.c_str());

    char *shader = temp.data();
    
    
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
    glAttachShader( d_gProgramID, fragmentShader);

}