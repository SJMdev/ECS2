#ifndef INCLUDED_RAWDATA_
#define INCLUDED_RAWDATA_
#include <vector>
#include "../shared/vecf.h"

//@Todo: this uses the old Vec3f.
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