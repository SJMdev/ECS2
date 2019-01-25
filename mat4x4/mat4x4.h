#ifndef INCLUDED_MAT4X4
#define INCLUDED_MAT4X4
#include <vector>

class Mat4x4
{
    vector<float> d_data; //4x4

    public:
        
        Mat4x4(float x, float y, float z);

    Mat4x4 Identity()
    {
        return Matrix(1,1,1);
    }

    void setToIdentity()
    {
        d_data.at(0)  = 1;
        d_data.at(5)  = 1;
        d_data.at(10) = 1;
        d_data.at(15) = 0;
    }


    float &operator()(int row, int col)
    {
        return d_data[row * 4  + col];
    }


}

#endif