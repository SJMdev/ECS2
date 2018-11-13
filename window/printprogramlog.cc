#include "window.ih"

void Window::printProgramLog(GLuint program)
{
    // Make sure name is shader
    if (glIsProgram (program))
    {
        //program log length;
        int infoLogLength = 0;
        int maxLength = infoLogLength;

        //get info string length
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &maxLength);

        // Allocate strring
        char *infoLog = new char[maxLength];

        // get info log
        glGetProgramInfoLog (program, maxLength, &infoLogLength, infoLog);
        if (infoLogLength > 0)
        {
            //print log
            printf("%s\n", infoLog);
        }

        //Deallocate string
        delete[] infoLog;
    }
    else
    {
        printf(" Name %d is not a program\n", program);
    }
}