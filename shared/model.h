#ifndef INCLUDED_MODEL_
#define INCLUDED_MODEL_
#include "vecf.h"
#include <vector>
#include "point.h"

struct Model
{
    std::vector<Vec3f> vertices;
    std::vector<Vec2f> uvs;
    std::vector<Vec3f> normals;
    std::vector<Vec3f> faces;
    std::vector<float> vertex_indices; //vector<int>?
    std::vector<float> normal_indices;
    std::vector<float> uv_indices;      //vector<int>?
};


#endif