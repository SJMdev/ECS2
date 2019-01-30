#include "matrix.ih"

Matrix4::MAtrix4(float x, float y, float z)
:
    d_data(vector<float>{
        x, 0, 0, 0,
        0, y, 0, 0,
        0, 0, z, 0,
        0, 0, 0, 1
    })
{

}