#ifndef INCLUDED_OBJECT
#define INCLUDED_OBJECT
#include "texture.h"
#include "vecf.h"
#include "vertex.h"

struct Object
{
    std::vector<Vec3f> raw_vertices;
    std::vector<Vec2f> raw_uvs;
    std::vector<Vec3f> raw_normals;
    std::vector<Vertex> interleaved_vertices;
    texture Texture;
};





#endif