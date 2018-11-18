#include "window.ih"

bool Window::initializeOpenGL()
{
    bool success = true;
    gProgramID = glCreateProgram();

    // in openGL, we bind shaders to a program. we can then render this program (I think).


    // create vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //get vertex source
    const GLchar* vertexShaderSource[] ={ R"glsl(
    #version 330 core
    layout (location = 0) in vec2 position;
    layout (location = 1) in vec3 color;

    out vec3 interpolatedColor;

    void main()
    { 
        interpolatedColor = color;
        vec4 pos = vec4(position, 0, 1);
        gl_Position = pos;
    }
    )glsl"};
        

    // We just wrote an inline shader. I would like to change this to a particular file. I believe the extension is GLSL.

    // set vertex Source
    glShaderSource(vertexShader, 1, vertexShaderSource, NULL);

    // compile vertex source
    glCompileShader(vertexShader);

    // check vertex shader for errors
    GLint vShaderCompiled = GL_FALSE;


    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vShaderCompiled);

    if (vShaderCompiled != GL_TRUE)
    {
        SDL_Log("Window::InitializeOpenGL: unable to compile vertex shader %d\n", vertexShader);
        printShaderLog(vertexShader);
        success = false;
    }
    else
    {
        SDL_Log("Window::InitializeOpenGL: compiled the vertex shader!");
        // attach vertex shader to program
        glAttachShader( gProgramID, vertexShader);
        // create fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        // get fragment source
        const GLchar* fragmentShaderSource[]= {R"glsl(
        #version 330 core
        
        in vec3 interpolatedColor;
        out vec4 rgba;
        
        void main()
        {
            rgba = vec4(interpolatedColor, 1);
        }
        )glsl"};

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