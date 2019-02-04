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


    Texture texture{};
    fillTexture(texture, string{"cat_norm.png"}); // read data from the .png image and store it in the texture.

    SDL_Log("texture width: %d", texture.width);
    SDL_Log("texture height:%d", texture.height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture.width, texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.image.data());

    // actually send the data to the buffer. We pass a reference to the raw data in interleaved vertices.
    glBufferData(GL_ARRAY_BUFFER, static_cast<int>(model.interleaved_vertices.size() * sizeof(Vertex)), model.interleaved_vertices.data(), GL_STATIC_DRAW);
     
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); // x, y, z
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(3 * sizeof(float))); //  skip  3: u, v,
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(5 * sizeof(float)));   //skip 5: r, g, b.

}