#include "window.ih"

bool Window::initializeOpenGL()
{
    bool success = true;
    gProgramID = glCreateProgram();
    // create vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //get vertex source
    const GLchar* vertexShaderSource[] =
    {
        "#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }"
    };

    // set vertex Source
    glShaderSource(vertexShader, 1, vertexShaderSource, NULL);

    // compile vertex source
    glCompileShader(vertexShader);

    // check vertex shader for errors
    GLint vShaderCompiled = GL_FALSE;

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vShaderCompiled);

    if (vShaderCompiled != GL_TRUE)
    {
        SDL_Log("Window::InitializeOpenGL: unable to copmile vertex shader %d\n", vertexShader);
        printShaderLog(vertexShader);
        success = false;
    }
    else
    {
        // attach vertex shader to program
        glAttachShader( gProgramID, vertexShader);

        // create fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        // get fragment source
        const GLchar* fragmentShaderSource[]=
        {
          "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }"  
        };

        //set fragment source
        glShaderSource( fragmentShader, 1, fragmentShaderSource, NULL);

        glCompileShader(fragmentShader);

        GLint fShaderCompiled = GL_FALSE;
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled);

        if (fShaderCompiled != GL_TRUE)
        {
            SDL_Log("Window::InitializeOpenGL: unable to compile fragment shader %d\n", fragmentShader);
            printShaderLog(fragmentShader);
            success = false;
        }
        else
        {
            // attach fragment shader to program
            glAttachShader(gProgramID, fragmentShader);

            //link program?
            glLinkProgram(gProgramID);

            //check for errors
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
                // get vertex Attribute Location:
                gVertexPos2DLocation = glGetAttribLocation( gProgramID, "LVertexPos2D");
                if (gVertexPos2DLocation == -1)
                {
                    SDL_Log("Window::InitializeOpenGL: LVertexPos2d is not a valid glsl program variable!\n");
                    success = false;
                }
                else
                {
                    //initialize clear color!
                    glClearColor( 0.f, 0.f, 0.f, 1.f); // r, g, b, a

                    //VBO data
                    GLfloat vertexData[] =
                    {
                        -0.5f, -0.5f,
                        0.5f, -0.5f,
                        0.5f, 0.5f,
                        -0.5f, 0.5f
                    };

                    //IBO data;
                    GLuint indexData[] = { 0, 1, 2, 3 };

                    //create VBO
                    glGenBuffers( 1, &gVBO);
                    glBindBuffer( GL_ARRAY_BUFFER, gVBO);
                    glBufferData( GL_ARRAY_BUFFER, 2* 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);

                    //create IBO:
                    glGenBuffers( 1, &gIBO);
                    glBindBuffer(GL_ARRAY_BUFFER, gIBO);
                    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4*sizeof(GLuint), indexData, GL_STATIC_DRAW);
                
                }
            }
        }
    }
    return success;
}