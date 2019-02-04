#ifndef INCLUDED_VECF_
#define INCLUDED_VECF_

struct Vec3f
{
    union 
    {
        struct 
        {
            float x;
            float y;
            float z;
        };
        // or
        float v[3];
     };
     
    Vec3f operator-( const Vec3f &rhs)
    {
        return Vec3f{ this->x -rhs.x , this->y - rhs.y, this->z - rhs.z };
    };

};


struct Vec4f
{
    union 
    {
        struct
        {
            float r;
            float g;
            float b;
            float a;
        }
        float v[4];
    }
};


struct Vec2f
{
    float u;
    float v;
};


#endif