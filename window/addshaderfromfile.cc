#include "window.ih"

void Window::addShaderFromFile(string &filename, GLenum shaderType, GLuint &shader)
{
    // sanity check?
    if (shaderType != GL_VERTEX_SHADER && shaderType != GL_FRAGMENT_SHADER)
    {
        SDL_Log("addShaderFromFile: invalid shader Type.");
    }
    //set Shader
    shader = glCreateShader(shaderType);

    //@cleanup: maybe directly transfer to string?
    std::ifstream ifs("shaders/" + filename);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

    char *shader_data = content.data();

    glShaderSource(shader, 1, &shader_data, NULL);
    glCompileShader(shader);

    GLint vShaderCompiled = GL_FALSE;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &vShaderCompiled);

    if (vShaderCompiled != GL_TRUE)
    {
        SDL_Log("Window::addVertexShaderFromSourceFile: unable to compile vertex shader %d\n", shader);
        printShaderLog(shader);
    }

    // do we do this here or somewhere else?
    // glAttachShader( d_gProgramID, shader);   


}