#include "window.ih"

void Window::initializeBuffers()
{ 
    GLsizei bufferCount = 1;
    // create VBO & VAO.
    glGenBuffers(bufferCount, &gVBO);     // glsizei n, GLuint *buffers
    glGenVertexArrays(bufferCount, &gVAO); // glsizei n, GLuinbt *arrays
    glBindVertexArray(gVAO);
    glBindBuffer(GL_ARRAY_BUFFER, gVBO);
    
}