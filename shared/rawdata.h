#ifndef INCLUDED_RAWDATA_
#define INCLUDED_RAWDATA_
#include <vector>
#include "../vector/vec3f.h"
#include "../vector/vec2f.h"



struct RawData
{
    std::vector<Vec3f> vertices;
    std::vector<Vec2f> uvs;
    std::vector<Vec3f> normals;
    std::vector<float> vertex_indices; 
    std::vector<float> uv_indices;
    std::vector<float> normal_indices;
};


#endif