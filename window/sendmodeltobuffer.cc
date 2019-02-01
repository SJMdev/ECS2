#include "window.ih"
#define BUFFER_OFFSET(i) ((void*)(i)) //hacky macro

void Window::sendModelToBuffer(Model &model)
{
    GLsizei objectCount = 1;


    // create VBO & VAO.
    glGenBuffers(objectCount, &gVBO);     // glsizei n, GLuint *buffers
    glGenVertexArrays(objectCount, &gVAO); // glsizei n, GLuinbt *arrays
    glBindVertexArray(gVAO);
    glBindBuffer(GL_ARRAY_BUFFER, gVBO);

    // Generate textures
    glGenTextures(objectCount, &gTBO);   
    glBindTexture(GL_TEXTURE_2D, gTBO);
    
    // Do some texture management here.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    SDL_Log("texture width: %d", );
    SDL_Log("texture height:");

    

    glBufferData(GL_ARRAY_BUFFER, static_cast<int>(model.interleaved_vertices.size() * sizeof(Vertex)), model.interleaved_vertices.data(), GL_STATIC_DRAW);
     
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); // x , y,z
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(5 * sizeof(float)));   //skip x,y,z,u,v. r,g,b!

}