#ifndef INCLUDED_LIGHT_
#define INCLUDED_LIGHT_
#include "../vector/vec3f.h"
#include "../matrix/mat4.h"

//@Todo: this uses the old Vec3f.
struct Light 
{
    Vec3f color; // r, g, b.
    Vec3f position;   
    
    Mat4 scaleMatrix;
    Mat4 rotationMatrix;
    Mat4 translationMatrix;
    Mat4 modelMatrix;
};



#endif