#ifndef INCLUDED_TEXTURE_
#define INCLUDED_TEXTURE_

#include <string>
#include <cstddef>
#include <vector>
#include "vecf.h"


struct Texture
{
    size_t width;
    size_t height;
    std::vector<unsigned char> image;
};



#endif