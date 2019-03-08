#include "loader.ih"

void Loader::loadTexture(std::string &filename,Texture &texture);
{
    std::string prepended_path = "textures/" + filename;
    std::vector<unsigned char> buffer, image;
    
    unsigned long width = 0;
    unsigned long height = 0;
    loadPNG(buffer, prepended_path);
    int error = decodePNG(texture.image, width, height, buffer.empty() ? 0 : &buffer[0], (unsigned long)buffer.size(), true);
    
    texture.width = width;
    texture.height = height;
    //if there's an error, display it
    if(error != 0)
        SDL_Log("error! %d", error);
    //the pixels are now in the vector "image", use it as texture
}