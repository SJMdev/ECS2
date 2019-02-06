// #include "window.ih"
// #define BUFFER_OFFSET(i) ((void*)(i)) //hacky macro

// void Window::drawTriangle()
// {
//          //initialize clear color!
//         glClearColor(0.2f, 0.5f, 0.7f, 0.0f); // r, g, b, a

//         // int arrayLength = 3;
//         std::vector<Point> verts = {{-1,0,1,0,0},{1,0,0,1,0},{0,1,0,0,1}};

//         GLsizei triangleCount = 1;

//         //create VBO
//         glGenBuffers( triangleCount, &gVBO);     // glsizei n, GLuint *buffers
//         glGenVertexArrays(triangleCount, &gVAO); // glsizei n, GLuinbt *arrays
//         glBindVertexArray(gVAO);
//         glBindBuffer(GL_ARRAY_BUFFER, gVBO);

//         glBufferData(GL_ARRAY_BUFFER, static_cast<int>(verts.size() * sizeof(Point)), verts.data(), GL_STATIC_DRAW);

//         glEnableVertexAttribArray(0);
//         glEnableVertexAttribArray(1);

//         glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Point), 0); // x , y
//         glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Point), BUFFER_OFFSET(2 * sizeof(float))); //r,g,b!      
// }