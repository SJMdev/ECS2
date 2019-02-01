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

        
    // struct Texture
    // {
    //     size_t width;
    //     size_t height;
    //     std::string filepath;
    //     vector<;
    // };

    Texture texture;
    fillTexture(texture, string{"../textures/cat_norm.png"});

    SDL_Log("texture width: %d", texture.width);
    SDL_Log("texture height:%d", texture.height);
    //image to bytes!
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture.width, texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.image.data());

    // actually send the data to the buffer. We pass a reference to the raw data in interleaved vertices.
    glBufferData(GL_ARRAY_BUFFER, static_cast<int>(model.interleaved_vertices.size() * sizeof(Vertex)), model.interleaved_vertices.data(), GL_STATIC_DRAW);
     
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); // x , y,z
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(5 * sizeof(float)));   //skip x,y,z,u,v. r,g,b!

}