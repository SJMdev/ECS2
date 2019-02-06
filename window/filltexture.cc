#include "window.ih"

// read a PNG
// fill a texture with the data, width & height.

void Window::fillTexture(Texture &texture, std::string &filename)
{
    std::string path = "textures/" + filename;
    std::vector<unsigned char> buffer, image;
    
    unsigned long width = 0;
    unsigned long height = 0;
    loadPNG(buffer, path);
    int error = decodePNG(texture.image, width, height, buffer.empty() ? 0 : &buffer[0], (unsigned long)buffer.size());
    
    texture.width = width;
    texture.height = height;
    //if there's an error, display it
    if(error != 0)
        SDL_Log("error! %d", error);
    //the pixels are now in the vector "image", use it as texture
}
