#include "window.ih"


void Window::fillTexture(Texture &texture, std::string &filename)
{
    std::string path = "textures/" + filename;
    std::vector<unsigned char> buffer, image;

    unsigned long width;
    unsigned long height;
    loadFile(buffer, path);
    int error = decodePNG(texture.image, width, height, buffer.empty() ? 0 : &buffer[0], (unsigned long)buffer.size());
    
    //if there's an error, display it
    if(error != 0)
        SDL_Log("error! %d", error);
    
    //the pixels are now in the vector "image", use it as texture, draw it, ...
    


}
