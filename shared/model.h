#ifndef INCLUDED_MODEL_
#define INCLUDED_MODEL_
#include "vecf.h"
#include <vector>

struct Model
{
    std::vector<Vec3f> vertices;
    std::vector<Vec2f> uvs;
    std::vector<Vec3f> normals;
    std::vector<Vec3f> faces;

};


#endif