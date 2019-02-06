#ifndef INCLUDED_CAMERA_
#define INCLUDED_CAMERA_
#include "../matrix/mat4.h"

struct Camera 
{
    Mat4 projectionMatrix;
    Mat4 modelViewMatrix;
    Mat4 mvpMatrix;
};


#endif