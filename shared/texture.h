#ifndef INCLUDED_TEXTURE_
#define INCLUDED_TEXTURE_
#include <string>
#include <cstddef>
#include <vector>
#include "vec.h";


struct Texture
{
    size_t width;
    size_t height;
    std::string filepath;
    vector<Vec2f> data;
;}


#endif