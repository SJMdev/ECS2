#include "window.ih"

void Window::sendTextureToBuffer(Object &object)
{
 
    // Generate textures
    glGenTextures(bufferCount, &object.TBO);   
    glBindTexture(GL_TEXTURE_2D, object.TBO);
    
    // Do some texture management here.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   // fillTexture(object.texture, string{"cat_diff_rot_flipped.png"}); // read data from the .png image and store it in the texture.

    SDL_Log("texture width: %d", object.texture.width);
    SDL_Log("texture height:%d", object.texture.height);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, object.texture.width, object.texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, object.texture.image.data());
}