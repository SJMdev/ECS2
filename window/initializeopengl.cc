#include "window.ih"
#define BUFFER_OFFSET(i) ((void*)(i)) //hacky macro


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

    //after setting the shader source, we need to free the vertexshadersource,
    // as openGL now has a copy

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
            SDL_Log("Window::initializeOpenGL: compiled fragmentShader");
            // attach fragment shader to program
            glAttachShader(gProgramID, fragmentShader);

            //link program!
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
                    //initialize clear color!
                    glClearColor(0.2f, 0.5f, 0.7f, 0.0f); // r, g, b, a

                    int arrayLength = 3;
                    std::vector<Point> verts = {{-1,0,1,0,0},{1,0,0,1,0},{0,1,0,0,1}};

                    GLsizei triangleCount = 1;

                    //create VBO
                    glGenBuffers( triangleCount, &gVBO);     // glsizei n, GLuint *buffers
                    glGenVertexArrays(triangleCount, &gVAO); // glsizei n, GLuinbt *arrays
                    glBindVertexArray(gVAO);
                    glBindBuffer(GL_ARRAY_BUFFER, gVBO);

                    glBufferData(GL_ARRAY_BUFFER, static_cast<int>(verts.size() * sizeof(Point)), verts.data(), GL_STATIC_DRAW);

                    glEnableVertexAttribArray(0);
                    glEnableVertexAttribArray(1);

                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Point), 0); // x , y
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Point), BUFFER_OFFSET(2 * sizeof(float))); //r,g,b!          
            }
        }
    }
    return success;
}