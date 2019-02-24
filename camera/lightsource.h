#ifndef INCLUDED_LIGHTSOURCE_
#define INCLUDED_LIGHTSOURCE_
#include "../shared/vecf.h"

//@Todo: this uses the old Vec3f.
struct Light 
{
    Vec3f color; // r, g, b.
    Vec3f position;   
    
    Mat4 scaleMatrix;
    Mat4 rotationmatrix;
    Mat4 translationMatrix;
};



#endif